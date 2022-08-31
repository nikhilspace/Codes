import pygame
from sys import exit

def display_score():
    current_time = int(pygame.time.get_ticks()/1000)
    score_surf = test_font.render(f'Score: {current_time}',True,(64,64,64))
    score_rect = score_surf.get_rect(center = (400,50))
    screen.blit(score_surf,score_rect)
    return current_time

pygame.init()
screen = pygame.display.set_mode((800,400))
pygame.display.set_caption('Game by Nikhil Mahar')
clock = pygame.time.Clock()
test_font = pygame.font.Font('C:/Users/NPC/Documents/Pygame/font/Pixeltype.ttf',50)
game_active = True
score = 0
sky_surface = pygame.image.load('C:/Users/NPC/Documents/Pygame/graphics/sky.png').convert()
ground_surface = pygame.image.load('C:/Users/NPC/Documents/Pygame/graphics/ground.png').convert()

snail_surf = pygame.image.load('C:/Users/NPC/Documents/Pygame/graphics/snail/snail1.png').convert_alpha()
snail_rect = snail_surf.get_rect(bottomright = (600,300))

player_surf = pygame.image.load('C:/Users/NPC/Documents/Pygame/graphics/player/player_walk_1.png').convert_alpha()
player_rect = player_surf.get_rect(midbottom = (80,300))
player_gravity = 0

player_stand = pygame.image.load('C:/Users/NPC/Documents/Pygame/graphics/Player/player_stand.png').convert_alpha()
player_stand = pygame.transform.rotozoom(player_stand,0,2)
player_stand_rect = player_stand.get_rect(center = (400,200))

game_name = test_font.render('Pixel Runner',True,(111,196,169))
game_name_rect = game_name.get_rect(center = (400,80))

game_message = test_font.render('Prss space to run',True,(111,196,169))
game_message_rect = game_message.get_rect(center = (400,320))

while True:
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            pygame.quit()
            exit()
        if event.type == pygame.MOUSEMOTION:
            if player_rect.collidepoint(event.pos) and player_rect.bottom == 300:
                player_gravity = -23
                 
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                if player_rect.bottom == 300:
                    player_gravity = -23
        else:
            if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
                game_active = True
                snail_rect.left = 800
                start_time = int(pygame.time.get_ticks()/1000)
    if game_active:
        screen.blit(sky_surface,(0,0))
        screen.blit(ground_surface,(0,300))
        display_score()
        score = display_score()
        snail_rect.x -= 4
        if snail_rect.right <= 0:
            snail_rect.left = 800
        screen.blit(snail_surf,snail_rect)

        player_gravity += 1
        player_rect.y += player_gravity
        if player_rect.bottom >= 300:
            player_rect.bottom = 300
        screen.blit(player_surf,player_rect)

        if snail_rect.colliderect(player_rect):
            game_active = False
    
    else:
        screen.fill((94,129,162))
        screen.blit(player_stand,player_stand_rect)

        score_message = test_font.render(f'Your score: {score}',True,(11,196,169))
        score_message_rect = score_message.get_rect(center = (400,330))
        screen.blit(game_name,game_name_rect)
        
        if score == 0:
            screen.blit(game_message,game_message_rect)
        else:
            screen.blit(score_message,score_message_rect)

    pygame.display.update()
    clock.tick(60)