#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "matrice.h"
#include "affichage.h"
#include "save.h"
#include <MLV/MLV_all.h>
#include <time.h>
#define T 4

int main()
{

    int x = 0, y = 0, j, i, v, w, cordx, cordy;
    int choix, click, afficher, var_charger = 0;
    int b;
    int score = 0;
    char *texte = NULL;
    int toto;
    piece p;
    piece suivant;
    terrain t;
    MLV_Music *sound;
    MLV_Button_state state;
    MLV_Keyboard_modifier mod = MLV_KEYBOARD_KMOD_NONE;
    MLV_Keyboard_button sym = MLV_KEYBOARD_NONE;
    MLV_Event event = MLV_NONE;
    MLV_Font *font;
    MLV_Font *font2;
    MLV_Font *font3;
    int frames = 5, layer = 1, channels = 1;
    MLV_Image *images[5];
    MLV_Image *goku;
    MLV_Image *wallpaper;
    MLV_Image *galaxie;
    ouvrir_fenetre("Tetris");
    font = MLV_load_font("./Fonts/kung_fu_master/kungfumaster.ttf", 80);
    font2 = MLV_load_font("./Fonts/minecrafter/Minecrafter.Reg.ttf", 40);
    font3 = MLV_load_font("./Fonts/minecrafter/Minecrafter.Reg.ttf", 60);
    goku = MLV_load_image("./images/dbzzz.png");
    choix = click = afficher = 0;
    wallpaper = MLV_load_image("./images/wallpaper.jpg");
    galaxie = MLV_load_image("./images/galaxie.jpg");

    srand(time(NULL));

    do
    {
        MLV_clear_window(MLV_COLOR_BLACK);
        MLV_draw_image(wallpaper, 0, 0);
        event = MLV_get_event(&sym, &mod, NULL, NULL, NULL, &x, &y, NULL, &state);
        if (afficher == 0)
        {
            afficher_menu(font, font2, font3, choix);
            if (event == MLV_KEY)
            {
                if (sym == MLV_KEYBOARD_z && state != MLV_RELEASED)
                {
                    click = 0;
                    if (choix == 0)
                    {
                        choix = 3;
                    }
                    else
                    {
                        choix--;
                    }
                }

                if (sym == MLV_KEYBOARD_RETURN && state == MLV_PRESSED)
                {
                    if (click == 0)
                    {
                        if (choix != 3)
                        {
                            afficher = choix + 1;
                        }
                        else
                        {
                            sym = MLV_KEYBOARD_b;
                            state = MLV_RELEASED;
                        }
                    }
                    else
                    {
                        click = 0;
                    }
                }

                if (sym == MLV_KEYBOARD_s && state != MLV_RELEASED)
                {
                    click = 0;
                    choix = (1 + choix) % 4;
                }
            }

            if (event == MLV_MOUSE_BUTTON && state == MLV_PRESSED && click == 0)
            {
                click = 1;
                state = MLV_RELEASED;
            }

            if (event == MLV_MOUSE_BUTTON && state == MLV_PRESSED && click == 1)
            {
                click = 2;
            }

            if (x > 515 && x < 765 && y > 300 && y < 360)
            {
                if (click == 1 && choix != 0)
                {
                    choix = 0;
                }
                if (click == 2 && choix == 0)
                {
                    afficher = choix + 1;
                }
            }

            if (x > 517 && x < 763 && y > 400 && y < 460)
            {
                if (click == 1 && choix != 1)
                {
                    choix = 1;
                }
                if (click == 2 && choix == 1)
                {
                    afficher = choix + 1;
                }
            }

            if (x > 595 && x < 685 && y > 500 && y < 560)
            {
                if (click == 1 && choix != 2)
                {
                    choix = 2;
                }
                if (click == 2 && choix == 2)
                {
                    afficher = choix + 1;
                }
            }

            if (x > 588 && x < 692 && y > 600 && y < 660)
            {
                if (click == 1 && choix != 3)
                {
                    choix = 3;
                }
                if (click == 2 && choix == 3)
                {
                    sym = MLV_KEYBOARD_b;
                    state = MLV_RELEASED;
                }
            }
            if (click == 2)
            {
                click = 1;
            }
        }
        if (afficher == 2)
        {
            init_terrain(&t);
            charger_partie(&t, "slot3.txt", &score);
            var_charger = 1;
            afficher = 1;
        }

        if (afficher == 3)
        {
            afficher_score();
            if (x > 1200 && x < 1230 && y > 20 && y < 50)
            {
                if (event == MLV_MOUSE_BUTTON && state == MLV_PRESSED)
                {
                    afficher = 0;
                }
            }
        }
        if (afficher == 1)
        {
            if (MLV_init_audio())
            {
                fprintf(stderr, "L'infrasctructure audio de la librairie MLV ne s'est pas correctement initialisé.");
                exit(1);
            }
            /*sound = MLV_load_music("sound/ffvii.wav");
            MLV_play_music(sound, 1., 400);*/
            if (var_charger != 1)
            {
                init_terrain(&t);

                toto = 1;
            }
            else
            {
                toto = 1;
                var_charger = 0;
            }
            MLV_clear_window(MLV_COLOR_BLACK);
            MLV_actualise_window();
            cree_piecealea(&p);
            while (toto == 1 && var_charger == 0)
            {
                b = 1;
                i = 2;
                for (j = 0; j < LARG; j++)
                {
                    if (t.field[i][j] == 2)
                    {
                        save_score(&score);
                        affichage_game_over(font2);
                        MLV_actualise_window();
                        MLV_wait_mouse(&v, &w);
                        if (verif_click(v, w) == 1)
                        {
                            animation_bouton_TA(font2);
                            MLV_stop_music();
                            MLV_free_music(sound);
                            MLV_free_audio();
                            toto = b = score = 0;
                            break;
                        }
                        if (verif_click(v, w) == 2)
                        {
                            animation_bouton_MENU(font2);
                            MLV_stop_all_sounds();
                            MLV_free_music(sound);
                            MLV_free_audio();
                            afficher = 0;
                            toto = b = score = 0;
                            break;
                        }
                    }
                }
                MLV_actualise_window();
                charger_piece_terrain(&p, &t);
                cree_piecealea(&suivant);
                affiche_terrain_mlv(&t, &suivant, &p, &score, galaxie);

                while (b == 1)
                {
                    event = MLV_get_event(
                        &sym, &mod, NULL,
                        &texte, NULL,
                        NULL, NULL, NULL,
                        &state);
                    switch (event)
                    {
                    case MLV_NONE:
                        break;
                    case MLV_KEY:
                        if (sym == MLV_KEYBOARD_j && state == MLV_PRESSED)
                        {
                            decale_piece_gauche(&t, &p);
                            MLV_flush_event_queue();
                        }
                        if (sym == MLV_KEYBOARD_l && state == MLV_PRESSED)
                        {
                            decale_piece_droite(&t, &p);
                            MLV_flush_event_queue();
                        }

                        if (sym == MLV_KEYBOARD_d && state == MLV_PRESSED)
                        {
                            rotat_piece_terrain(&p, &t);
                            affiche_terrain_mlv(&t, &suivant, &p, &score, galaxie);
                            MLV_flush_event_queue();
                        }

                        if (sym == MLV_KEYBOARD_k && state == MLV_PRESSED)
                        {
                            accelere_piece(&t, &p);
                        }
                        if (sym == MLV_KEYBOARD_ESCAPE && state == MLV_PRESSED)
                        {
                            afficher_pause(font2);
                            MLV_actualise_window();

                            while (1)
                            {
                                MLV_wait_mouse(&v, &w);
                                if (verif_click_pause(v, w) == 1)
                                {
                                    break;
                                }
                                if (verif_click_pause(v, w) == 2)
                                {
                                    MLV_stop_music();
                                    MLV_free_music(sound);
                                    MLV_free_audio();
                                    afficher = 0;
                                    toto = b = score = 0;
                                    break;
                                }
                                if (verif_click_pause(v, w) == 3)
                                {
                                    save_partie(&t, "slot3.txt", &score);
                                    while (1)
                                    {
                                        afficher_menu_save(font2, &cordx, &cordy);
                                    }
                                    break;
                                    /* afficher = 0; */
                                    /* toto = b = score = 0; */
                                    /* break; */
                                }
                                MLV_actualise_window();
                            }
                        }
                        break;
                    default:
                        break;
                    }

                    if (peut_tomber_piece(&t))
                    {
                        tombe_piece(&t, &p);
                    }
                    else
                    {
                        transforme_piece_block(&t);
                        p = suivant;
                        b = 0;
                    }
                    if (supprimer_ligne(&t, &score) == 0)
                    {
                        animation(goku, "./images/dbzzz.png", frames, layer, channels, images);
                    }

                    affiche_terrain_mlv(&t, &suivant, &p, &score, galaxie);
                    dessin_score(font2, &score);
                    if (score >= 200)
                    {
                        MLV_wait_milliseconds(120);
                    }
                    else if (score >= 300)
                    {
                        MLV_wait_milliseconds(110);
                    }
                    else if (score >= 400)
                    {
                        MLV_wait_milliseconds(100);
                    }
                    else
                    {
                        MLV_wait_milliseconds(140);
                    }
                    MLV_actualise_window();
                }
                MLV_actualise_window();
            }
        }
        MLV_actualise_window();
    } while (!(sym == MLV_KEYBOARD_b && state == MLV_RELEASED)); /* tant qu'on n'appuie pas sur le boutton b */
    MLV_free_font(font);
    MLV_free_font(font2);
    MLV_free_font(font3);
    MLV_free_window();
    exit(EXIT_SUCCESS);
}
