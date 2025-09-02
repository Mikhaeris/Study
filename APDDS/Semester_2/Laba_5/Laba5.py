import pygame
import math

W = 600
H = 600

def get_pentagon_points(center, radius):
    points = []
    
    for i in range(5):
        angle_radians = math.radians(i * 72)
        x = center[0] + radius * math.cos(angle_radians)
        y = center[1] + radius * math.sin(angle_radians)
        
        points.append((x, y))
    
    return points

def draw_fractal_pentagon(screen, center, radius, depth):
    if depth <= 0:
        return

    points = get_pentagon_points(center, radius)
  
    for point in points:
        draw_fractal_pentagon(screen, point, radius//2, depth - 1)

    pygame.draw.polygon(screen, (255, 105, 180), points)
    pygame.draw.polygon(screen, (0, 0, 0), points, 2)


pygame.init()
screen = pygame.display.set_mode((W, H))
pygame.display.set_caption("Laba5")

screen.fill((255, 255, 255))
draw_fractal_pentagon(screen, (W//2, H//2), 150, 5)
pygame.display.flip()

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

pygame.quit()