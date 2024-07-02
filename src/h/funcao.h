#ifndef _FUNCAO_H_
#define _FUNCAO_H_
#include "../include/allegro.h"

float cena=1,x=-370,y=300;//variavel globais
bool gravidade=true, pular=false,limite=true,queda=false,espera_atack=false,stop_conte=false;
int  hit_x=0,hit_y=0;
//coisas do player
int altura=0,p1_xy=0,p2_x=0,p3_y=0,p4_xy=0,frame=0,frame_atual=0,frame_v=0,conte=0,vidas=3,inven[5]={0,-1,-1,-1,-1},ajuste=0,hp=5;
float vel_x=4.5,vel_y=0,ace_y=0.5,pos_player_x=100,pos_player_y=400;
bool stop_frame=false,atack_frame=false,andando=false,agarra=false,cogela_pula=false,mante_agarra=false,dont_move=false,tocou=false;
//coisas do inimigo
int qua=0,qua_span=0;
bool parou_qua=false;
//coisas do item
int pos_x_item[5][10]={0,-1,-1,-1,-1,-1,-1,-1,-1,-1},pos_y_item[5][10]={0,-1,-1,-1,-1,-1,-1,-1,-1,-1},valor,pos_x_bomb=0,pos_y_bomb=0,lado_atual_bomb=-1;
int hit_x_bomb=-2000,hit_y_bomb=-2000,qtd_bomb=0;
bool bomba=false,tempo_bomb=false;


enum{
	
	game_over=-1,
	play=1,
	stop=2,
	stage_2=100,
	stage_3=101,
	stage_4=102,
	stage_5=103,
	stage_6=104,
	stage_7=105,
	stage_8=106,
	stage_9=107,
	grama=3,
	terra=4,
	terra_menor=5,
	terra_lado_1=6,
	terra_lado_2=7,
	terra_lado_3=8,
	terra_lado_4=9,
	bloco=10,
	bloco_lado_1=11,
	bloco_lado_2=12,
	bloco_lado_3=13,
	bloco_lado_4=14,
	bloco_vivo=15,
	inimigo_1=20,
	inimigo_2=21,
	inimigo_3=22,
	inimigo_4=23,
	inimigo_5=24,
	bau=50
		
	};

int tecla_ante[KEY_MAX];

#endif