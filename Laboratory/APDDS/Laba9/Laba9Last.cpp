#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Worker {
	int workerFree;
	int workerTime;
};

int main() {
	const int countWorkers = 2;
	const int pump = 4;
	const int timeDetail = 10;
	const int countHours = 60;

	vector<int> queueF;
	vector<Worker> vecWorkers(countWorkers, { 1, 0 });

	vector<int> timeInQueue(countHours / pump + 1, 0);
	int totalDetail = 0;

	int summTime = 0, countClients = 0;
	for (int hour = 1; hour <= countHours; hour++) {

		if (hour % pump == 1) {
			totalDetail++;
			queueF.push_back(0);
			countClients++;
		}

		for (auto& worker : vecWorkers) {
			if (worker.workerTime == timeDetail) {
				worker.workerFree = true;
				worker.workerTime = 0;
			}
		}

		for (auto& worker : vecWorkers) {
			if (!worker.workerFree) {
				worker.workerTime++;
			}
		}

		for (auto& worker : vecWorkers) {
			if (worker.workerFree && !queueF.empty()) {
				summTime += queueF[0];
				queueF.erase(queueF.begin());

				worker.workerFree = false;
				worker.workerTime = 1;
			}
		}

		for (auto& det : queueF) {
			det++;
		}

	}

	cout << "Count detail in queue: " << queueF.size() << endl;

	int summNow = 0;
	for (auto& det : queueF) {
		summNow += det;
	}

	cout << "Average time: " << static_cast<double>(summTime + summNow) / countClients << endl;

	return 0;
}










Option Explicit
Const p = 4                         '   ïîòîê êëèåíòîâ
Const TotalTime = 60                '   îáùåå âðåìÿ
Const t = 10                        '   âðåìÿ îáñëóæèâàíèÿ îäíîãî êëèåíòà
Const nClient = TotalTime \ p + 1   '   ìàêñèìàëüíîå êîëè÷åñòâî êëèåíòîâ

Type DataClient                     '   äàííûå êëèåíòà
    Number As Integer               '   íîìåð êëèåíòà
    Next As Integer                 '   ññûëêà íà ñëåäóþùåãî
    SummaT As Integer               '   âðåìÿ, ïðîâåäåííîå â î÷åðåäè
End Type

Dim Sequence(nClient) As DataClient     ' ìàññèâ êëèåíòîâ (î÷åðåäü)
Dim KassaFree As Boolean                ' ñâîáîäíà ëè êàññà
Dim KassaTime As Integer                '
Dim kClient As Integer                  ' òåêóùåå êîëè÷åñòâî êëèåíòîâ
Dim Tail As Integer                     ' óêàçàòåëü íà õâîñò î÷åðåäè
Dim SummaTime As Integer, Average As Single
'
Sub AddToSequence(kClient)
    With Sequence(kClient)
        .Number = kClient
        .Next = 0
        .SummaT = 0
    End With
    Sequence(kClient - 1).Next = kClient
    Tail = kClient
End Sub
'
Sub SdvigSequence()
    Sequence(0).Next = Sequence(0).Next + 1
    KassaFree = False
End Sub
'
Sub Main()
Dim i As Integer, j As Integer

With Sequence(0)
    .Number = 0
    .SummaT = 0
    .Next = 1
End With

Tail = 0
KassaFree = True
KassaTime = 0
kClient = 0

For i = 1 To TotalTime
    If i Mod p = 1 Then
        kClient = kClient + 1
        AddToSequence (kClient)
    End If
    
    If KassaTime = t Then
        KassaFree = True
        KassaTime = 0
    End If
    
    If KassaFree = False Then
        KassaTime = KassaTime + 1
    End If
    
    If KassaFree Then
         SdvigSequence
         KassaFree = False
         KassaTime = 1
    End If

    For j = Sequence(0).Next To Tail
        Sequence(j).SummaT = Sequence(j).SummaT + 1
    Next

    Cells(i + 3, 15) = Sequence(0).Next
    Cells(i + 3, 16) = Tail
    Cells(i + 3, 17) = KassaTime

    For j = Sequence(0).Next To Tail
        Cells(i + 3, j + 17) = Sequence(j).Number
    Next
Next

SummaTime = 0
For i = 1 To Tail
    SummaTime = SummaTime + Sequence(i).SummaT
    Cells(i + 10, 12) = Sequence(i).SummaT
Next
Average = SummaTime / kClient
Cells(3, 13) = Average
    
End Sub

