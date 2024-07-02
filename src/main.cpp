#include <iostream>
#include "include/allegro.h"
#include "include/logg.h"
#include "h/classe.h"
#include "h/funcao.h"
#include "classe.cpp"

using namespace std;
volatile bool fecha= false;
volatile int fps= 0,mile=0;

#include "funcao.cpp"

void fechajanela();
void allegro_start(const string& title,int height,int width);
void tempo_do_sistema();
void ani();


void game(BITMAP* buffer);
void game_2(BITMAP* buffer);
void game_3(BITMAP* buffer);
void game_4(BITMAP* buffer);
void game_5(BITMAP* buffer);
void game_6(BITMAP* buffer);
void game_7(BITMAP* buffer);
void game_8(BITMAP* buffer);
void game_9(BITMAP* buffer);
void recomeca(BITMAP* buffer);




int main(){
	
	
	allegro_start("rpg",1200,800);
	LOCK_VARIABLE(fecha);
	LOCK_FUNCTION(fechajanela);
	LOCK_VARIABLE(fps);
	LOCK_FUNCTION(tempo_do_sistema);
	
	install_int_ex(tempo_do_sistema,BPS_TO_TIMER(60));
	install_int_ex(ani,MSEC_TO_TIMER(1));
	set_close_button_callback(fechajanela);
	
	
	BITMAP* buffer=create_bitmap(SCREEN_W,SCREEN_H);
	
	while (!fecha){
		
		while(fps>=1){
			
			if(cena==play){
				
				game(buffer);
			}else if(cena==stage_2){
				
				
				game_2(buffer);
				
			}else if(cena==stage_3){
				
				
				game_3(buffer);
				
				
			}else if(cena==stage_4){
				
				
				game_4(buffer);
				
				
			}else if(cena==stage_5){
				
				
				game_5(buffer);
				
				
			}else if(cena==stage_6){
				
				
				game_6(buffer);
				
				
			}else if(cena==stage_7){
				
				
				game_7(buffer);
				
				
			}else if(cena==stage_8){
				
				
				game_8(buffer);
				
				
			}else if(cena==stage_9){
				
				
				game_9(buffer);
				
				
			}else if(cena==game_over){
				
				
				recomeca(buffer);
				
				
			}
			
			
			
			
			fps--;
		}
		
		
	}
	
	destroy_bitmap(buffer);
	
	allegro_exit();
	return 0;
	
}

END_OF_MAIN();



void game(BITMAP* buffer){
	
	bool fgame=false;
	
	int linha,coluna;
	int** mapa=load_map("mapa/mapa.txt",&linha,&coluna);
	BITMAP* player=load_bitmap("sprite/play.bmp",NULL);
	BITMAP* m=load_bitmap("sprite/mapa.bmp",NULL);
	BITMAP* adv=load_bitmap("sprite/enemy.bmp",NULL);
	BITMAP* img_item=load_bitmap("sprite/item.bmp",NULL);
	
	Lista_inimi* l=create_lista();
	Lista_inimi_5* l5=create_lista_5();
	
	while(!fecha && !fgame){
		
		
		while(fps>=1){
			
			atualiza_tecla();
			player_control(buffer,player);
			lanca_bomba(img_item,buffer,mile);
			update_lista(l,adv,buffer,mile);
			update_lista_5(l5,adv,buffer,mile);
			
			
			
			desenha_mapa(img_item,m,buffer,mapa,linha,coluna,l,NULL,NULL,NULL,l5);
			fgame=meu_status(buffer,font,fgame);
			mostra_item(img_item,buffer);
			meu_item(img_item,buffer);
			seleciona_item(player,img_item,buffer,mile);
			draw_sprite(screen,buffer,0,0);
			clear_to_color(buffer,makecol(34,66,90));
			
			fps--;
		}
		
		
		
	}
	
	
	destroy_lista(l);
	destroy_lista_5(l5);
	fecha_mapa(mapa,linha);
	destroy_bitmap(img_item);
	destroy_bitmap(adv);
	destroy_bitmap(m);
	destroy_bitmap(player);
	
}


void game_2(BITMAP* buffer){
	
	bool fgame=false;
	
	int linha,coluna;
	int** mapa=load_map("mapa/mapa2.txt",&linha,&coluna);
	BITMAP* player=load_bitmap("sprite/play.bmp",NULL);
	BITMAP* m=load_bitmap("sprite/mapa.bmp",NULL);
	BITMAP* adv=load_bitmap("sprite/enemy.bmp",NULL);
	BITMAP* img_item=load_bitmap("sprite/item.bmp",NULL);
	
	
	SAMPLE* música=logg_load("musica/tema2.ogg");
	
	Lista_inimi* l=create_lista();
	Lista_inimi_2* l2=create_lista_2();
	Lista_inimi_3* l3=create_lista_3();
	Lista_inimi_4* l4=create_lista_4();
	
	play_sample(música,255,0,1000,true);
	
	while(!fecha && !fgame){
		
		
		while(fps>=1){
			
			atualiza_tecla();
			player_control(buffer,player);
			lanca_bomba(img_item,buffer,mile);
			update_lista(l,adv,buffer,mile);
			update_lista_2(l2,adv,buffer,mile);
			update_lista_3(l3,adv,buffer,mile);
			update_lista_4(l4,adv,buffer,mile);
			
			
			
			desenha_mapa(img_item,m,buffer,mapa,linha,coluna,l,l2,l3,l4);
			fgame=meu_status(buffer,font,fgame);
			mostra_item(img_item,buffer);
			meu_item(img_item,buffer);
			seleciona_item(player,img_item,buffer,mile);
			draw_sprite(screen,buffer,0,0);
			clear_to_color(buffer,makecol(34,66,90));
			
			fps--;
		}
		
		
		
	}
	
	
	destroy_lista(l);
	destroy_lista_2(l2);
	destroy_lista_3(l3);
	destroy_lista_4(l4);
	fecha_mapa(mapa,linha);
	destroy_bitmap(img_item);
	destroy_bitmap(adv);
	destroy_bitmap(m);
	destroy_bitmap(player);
	destroy_sample(música);
	
}


void game_3(BITMAP* buffer){
	
	bool fgame=false;
	
	int linha,coluna;
	int** mapa=load_map("mapa/mapa2.txt",&linha,&coluna);
	BITMAP* player=load_bitmap("sprite/play.bmp",NULL);
	BITMAP* m=load_bitmap("sprite/mapa.bmp",NULL);
	BITMAP* adv=load_bitmap("sprite/enemy.bmp",NULL);
	BITMAP* img_item=load_bitmap("sprite/item.bmp",NULL);
	
	
	SAMPLE* música=logg_load("musica/tema2.ogg");
	
	Lista_inimi* l=create_lista();
	Lista_inimi_2* l2=create_lista_2();
	Lista_inimi_3* l3=create_lista_3();
	Lista_inimi_4* l4=create_lista_4();
	
	play_sample(música,255,0,1000,true);
	
	while(!fecha && !fgame){
		
		
		while(fps>=1){
			
			atualiza_tecla();
			player_control(buffer,player);
			lanca_bomba(img_item,buffer,mile);
			update_lista(l,adv,buffer,mile);
			update_lista_2(l2,adv,buffer,mile);
			update_lista_3(l3,adv,buffer,mile);
			update_lista_4(l4,adv,buffer,mile);
			
			
			
			desenha_mapa(img_item,m,buffer,mapa,linha,coluna,l,l2,l3,l4);
			fgame=meu_status(buffer,font,fgame);
			mostra_item(img_item,buffer);
			meu_item(img_item,buffer);
			seleciona_item(player,img_item,buffer,mile);
			draw_sprite(screen,buffer,0,0);
			clear_to_color(buffer,makecol(34,66,90));
			
			fps--;
		}
		
		
		
	}
	
	
	destroy_lista(l);
	destroy_lista_2(l2);
	destroy_lista_3(l3);
	destroy_lista_4(l4);
	fecha_mapa(mapa,linha);
	destroy_bitmap(img_item);
	destroy_bitmap(adv);
	destroy_bitmap(m);
	destroy_bitmap(player);
	destroy_sample(música);
	
}

void game_4(BITMAP* buffer){
	
	bool fgame=false;
	
	int linha,coluna;
	int** mapa=load_map("mapa/mapa2.txt",&linha,&coluna);
	BITMAP* player=load_bitmap("sprite/play.bmp",NULL);
	BITMAP* m=load_bitmap("sprite/mapa.bmp",NULL);
	BITMAP* adv=load_bitmap("sprite/enemy.bmp",NULL);
	BITMAP* img_item=load_bitmap("sprite/item.bmp",NULL);
	
	
	SAMPLE* música=logg_load("musica/tema2.ogg");
	
	Lista_inimi* l=create_lista();
	Lista_inimi_2* l2=create_lista_2();
	Lista_inimi_3* l3=create_lista_3();
	Lista_inimi_4* l4=create_lista_4();
	
	play_sample(música,255,0,1000,true);
	
	while(!fecha && !fgame){
		
		
		while(fps>=1){
			
			atualiza_tecla();
			player_control(buffer,player);
			lanca_bomba(img_item,buffer,mile);
			update_lista(l,adv,buffer,mile);
			update_lista_2(l2,adv,buffer,mile);
			update_lista_3(l3,adv,buffer,mile);
			update_lista_4(l4,adv,buffer,mile);
			
			
			
			desenha_mapa(img_item,m,buffer,mapa,linha,coluna,l,l2,l3,l4);
			fgame=meu_status(buffer,font,fgame);
			mostra_item(img_item,buffer);
			meu_item(img_item,buffer);
			seleciona_item(player,img_item,buffer,mile);
			draw_sprite(screen,buffer,0,0);
			clear_to_color(buffer,makecol(34,66,90));
			
			fps--;
		}
		
		
		
	}
	
	
	destroy_lista(l);
	destroy_lista_2(l2);
	destroy_lista_3(l3);
	destroy_lista_4(l4);
	fecha_mapa(mapa,linha);
	destroy_bitmap(img_item);
	destroy_bitmap(adv);
	destroy_bitmap(m);
	destroy_bitmap(player);
	destroy_sample(música);
	
}

void game_5(BITMAP* buffer){
	
	bool fgame=false;
	
	int linha,coluna;
	int** mapa=load_map("mapa/mapa2.txt",&linha,&coluna);
	BITMAP* player=load_bitmap("sprite/play.bmp",NULL);
	BITMAP* m=load_bitmap("sprite/mapa.bmp",NULL);
	BITMAP* adv=load_bitmap("sprite/enemy.bmp",NULL);
	BITMAP* img_item=load_bitmap("sprite/item.bmp",NULL);
	
	
	SAMPLE* música=logg_load("musica/tema2.ogg");
	
	Lista_inimi* l=create_lista();
	Lista_inimi_2* l2=create_lista_2();
	Lista_inimi_3* l3=create_lista_3();
	Lista_inimi_4* l4=create_lista_4();
	
	play_sample(música,255,0,1000,true);
	
	while(!fecha && !fgame){
		
		
		while(fps>=1){
			
			atualiza_tecla();
			player_control(buffer,player);
			lanca_bomba(img_item,buffer,mile);
			update_lista(l,adv,buffer,mile);
			update_lista_2(l2,adv,buffer,mile);
			update_lista_3(l3,adv,buffer,mile);
			update_lista_4(l4,adv,buffer,mile);
			
			
			
			desenha_mapa(img_item,m,buffer,mapa,linha,coluna,l,l2,l3,l4);
			fgame=meu_status(buffer,font,fgame);
			mostra_item(img_item,buffer);
			meu_item(img_item,buffer);
			seleciona_item(player,img_item,buffer,mile);
			draw_sprite(screen,buffer,0,0);
			clear_to_color(buffer,makecol(34,66,90));
			
			fps--;
		}
		
		
		
	}
	
	
	destroy_lista(l);
	destroy_lista_2(l2);
	destroy_lista_3(l3);
	destroy_lista_4(l4);
	fecha_mapa(mapa,linha);
	destroy_bitmap(img_item);
	destroy_bitmap(adv);
	destroy_bitmap(m);
	destroy_bitmap(player);
	destroy_sample(música);
	
}


void game_6(BITMAP* buffer){
	
	bool fgame=false;
	
	int linha,coluna;
	int** mapa=load_map("mapa/mapa2.txt",&linha,&coluna);
	BITMAP* player=load_bitmap("sprite/play.bmp",NULL);
	BITMAP* m=load_bitmap("sprite/mapa.bmp",NULL);
	BITMAP* adv=load_bitmap("sprite/enemy.bmp",NULL);
	BITMAP* img_item=load_bitmap("sprite/item.bmp",NULL);
	
	
	SAMPLE* música=logg_load("musica/tema2.ogg");
	
	Lista_inimi* l=create_lista();
	Lista_inimi_2* l2=create_lista_2();
	Lista_inimi_3* l3=create_lista_3();
	Lista_inimi_4* l4=create_lista_4();
	
	play_sample(música,255,0,1000,true);
	
	while(!fecha && !fgame){
		
		
		while(fps>=1){
			
			atualiza_tecla();
			player_control(buffer,player);
			lanca_bomba(img_item,buffer,mile);
			update_lista(l,adv,buffer,mile);
			update_lista_2(l2,adv,buffer,mile);
			update_lista_3(l3,adv,buffer,mile);
			update_lista_4(l4,adv,buffer,mile);
			
			
			
			desenha_mapa(img_item,m,buffer,mapa,linha,coluna,l,l2,l3,l4);
			fgame=meu_status(buffer,font,fgame);
			mostra_item(img_item,buffer);
			meu_item(img_item,buffer);
			seleciona_item(player,img_item,buffer,mile);
			draw_sprite(screen,buffer,0,0);
			clear_to_color(buffer,makecol(34,66,90));
			
			fps--;
		}
		
		
		
	}
	
	
	destroy_lista(l);
	destroy_lista_2(l2);
	destroy_lista_3(l3);
	destroy_lista_4(l4);
	fecha_mapa(mapa,linha);
	destroy_bitmap(img_item);
	destroy_bitmap(adv);
	destroy_bitmap(m);
	destroy_bitmap(player);
	destroy_sample(música);
	
}

void game_7(BITMAP* buffer){
	
	bool fgame=false;
	
	int linha,coluna;
	int** mapa=load_map("mapa/mapa2.txt",&linha,&coluna);
	BITMAP* player=load_bitmap("sprite/play.bmp",NULL);
	BITMAP* m=load_bitmap("sprite/mapa.bmp",NULL);
	BITMAP* adv=load_bitmap("sprite/enemy.bmp",NULL);
	BITMAP* img_item=load_bitmap("sprite/item.bmp",NULL);
	
	
	SAMPLE* música=logg_load("musica/tema2.ogg");
	
	Lista_inimi* l=create_lista();
	Lista_inimi_2* l2=create_lista_2();
	Lista_inimi_3* l3=create_lista_3();
	Lista_inimi_4* l4=create_lista_4();
	
	play_sample(música,255,0,1000,true);
	
	while(!fecha && !fgame){
		
		
		while(fps>=1){
			
			atualiza_tecla();
			player_control(buffer,player);
			lanca_bomba(img_item,buffer,mile);
			update_lista(l,adv,buffer,mile);
			update_lista_2(l2,adv,buffer,mile);
			update_lista_3(l3,adv,buffer,mile);
			update_lista_4(l4,adv,buffer,mile);
			
			
			
			desenha_mapa(img_item,m,buffer,mapa,linha,coluna,l,l2,l3,l4);
			fgame=meu_status(buffer,font,fgame);
			mostra_item(img_item,buffer);
			meu_item(img_item,buffer);
			seleciona_item(player,img_item,buffer,mile);
			draw_sprite(screen,buffer,0,0);
			clear_to_color(buffer,makecol(34,66,90));
			
			fps--;
		}
		
		
		
	}
	
	
	destroy_lista(l);
	destroy_lista_2(l2);
	destroy_lista_3(l3);
	destroy_lista_4(l4);
	fecha_mapa(mapa,linha);
	destroy_bitmap(img_item);
	destroy_bitmap(adv);
	destroy_bitmap(m);
	destroy_bitmap(player);
	destroy_sample(música);
	
}

void game_8(BITMAP* buffer){
	
	bool fgame=false;
	
	int linha,coluna;
	int** mapa=load_map("mapa/mapa2.txt",&linha,&coluna);
	BITMAP* player=load_bitmap("sprite/play.bmp",NULL);
	BITMAP* m=load_bitmap("sprite/mapa.bmp",NULL);
	BITMAP* adv=load_bitmap("sprite/enemy.bmp",NULL);
	BITMAP* img_item=load_bitmap("sprite/item.bmp",NULL);
	
	
	SAMPLE* música=logg_load("musica/tema2.ogg");
	
	Lista_inimi* l=create_lista();
	Lista_inimi_2* l2=create_lista_2();
	Lista_inimi_3* l3=create_lista_3();
	Lista_inimi_4* l4=create_lista_4();
	
	play_sample(música,255,0,1000,true);
	
	while(!fecha && !fgame){
		
		
		while(fps>=1){
			
			atualiza_tecla();
			player_control(buffer,player);
			lanca_bomba(img_item,buffer,mile);
			update_lista(l,adv,buffer,mile);
			update_lista_2(l2,adv,buffer,mile);
			update_lista_3(l3,adv,buffer,mile);
			update_lista_4(l4,adv,buffer,mile);
			
			
			
			desenha_mapa(img_item,m,buffer,mapa,linha,coluna,l,l2,l3,l4);
			fgame=meu_status(buffer,font,fgame);
			mostra_item(img_item,buffer);
			meu_item(img_item,buffer);
			seleciona_item(player,img_item,buffer,mile);
			draw_sprite(screen,buffer,0,0);
			clear_to_color(buffer,makecol(34,66,90));
			
			fps--;
		}
		
		
		
	}
	
	
	destroy_lista(l);
	destroy_lista_2(l2);
	destroy_lista_3(l3);
	destroy_lista_4(l4);
	fecha_mapa(mapa,linha);
	destroy_bitmap(img_item);
	destroy_bitmap(adv);
	destroy_bitmap(m);
	destroy_bitmap(player);
	destroy_sample(música);
	
}

void game_9(BITMAP* buffer){
	
	bool fgame=false;
	
	int linha,coluna;
	int** mapa=load_map("mapa/mapa2.txt",&linha,&coluna);
	BITMAP* player=load_bitmap("sprite/play.bmp",NULL);
	BITMAP* m=load_bitmap("sprite/mapa.bmp",NULL);
	BITMAP* adv=load_bitmap("sprite/enemy.bmp",NULL);
	BITMAP* img_item=load_bitmap("sprite/item.bmp",NULL);
	
	
	SAMPLE* música=logg_load("musica/tema2.ogg");
	
	Lista_inimi* l=create_lista();
	Lista_inimi_2* l2=create_lista_2();
	Lista_inimi_3* l3=create_lista_3();
	Lista_inimi_4* l4=create_lista_4();
	
	play_sample(música,255,0,1000,true);
	
	while(!fecha && !fgame){
		
		
		while(fps>=1){
			
			atualiza_tecla();
			player_control(buffer,player);
			lanca_bomba(img_item,buffer,mile);
			update_lista(l,adv,buffer,mile);
			update_lista_2(l2,adv,buffer,mile);
			update_lista_3(l3,adv,buffer,mile);
			update_lista_4(l4,adv,buffer,mile);
			
			
			
			desenha_mapa(img_item,m,buffer,mapa,linha,coluna,l,l2,l3,l4);
			fgame=meu_status(buffer,font,fgame);
			mostra_item(img_item,buffer);
			meu_item(img_item,buffer);
			seleciona_item(player,img_item,buffer,mile);
			draw_sprite(screen,buffer,0,0);
			clear_to_color(buffer,makecol(34,66,90));
			
			fps--;
		}
		
		
		
	}
	
	
	destroy_lista(l);
	destroy_lista_2(l2);
	destroy_lista_3(l3);
	destroy_lista_4(l4);
	fecha_mapa(mapa,linha);
	destroy_bitmap(img_item);
	destroy_bitmap(adv);
	destroy_bitmap(m);
	destroy_bitmap(player);
	destroy_sample(música);
	
}



void recomeca(BITMAP* buffer){
	bool breset=false;
	
	
	while (!fecha && !breset){
		
		while(fps>=1){
			
			
			textprintf_centre(buffer,font,SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),"fim de jogo");
			draw_sprite(screen,buffer,0,0);
			clear(buffer);
			
			
			fps--;
		}
		
	}
	
	
	
	
	
	
	
}



void allegro_start(const string& title,int height,int width){
	
	
	allegro_init();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,height,width,0,0);
	set_window_title(title.data());
	
	
	install_keyboard();
	install_timer();
	//detect_digi_driver(0);
	install_sound(DIGI_AUTODETECT,MIDI_NONE,NULL);
	install_mouse();
	
	
	
	
	
}

void tempo_do_sistema(){fps++;}
END_OF_FUNCTION(tempo_do_sistema);

void fechajanela(){
	
	fecha=true;
}
END_OF_FUNCTION(fechajanela);

void ani(){mile++;}
END_OF_FUNCTION(ani);