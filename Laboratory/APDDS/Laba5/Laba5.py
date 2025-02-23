import pygame
import math

WIDTH, HEIGHT = 600, 600

def get_pentagon_points(center, radius, rotation=0):
    return [
        (center[0] + radius * math.cos(math.radians(rotation + i * 72)),
         center[1] + radius * math.sin(math.radians(rotation + i * 72)))
        for i in range(5)
    ]

def draw_fractal_pentagon(screen, center, radius, rotation, depth):
    if depth <= 0:
        return

    points = get_pentagon_points(center, radius, rotation)
  
    for point in points:
        draw_fractal_pentagon(screen, point, radius // 2, rotation, depth - 1)

    pygame.draw.polygon(screen, (255, 105, 180), points)
    pygame.draw.polygon(screen, (0, 0, 0), points, 2)

def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Laba5")

    screen.fill((255, 255, 255))
    draw_fractal_pentagon(screen, (WIDTH//2, HEIGHT//2), 150, 0, 5)
    pygame.display.flip()

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

    pygame.quit()

if __name__ == "__main__":
    main()
