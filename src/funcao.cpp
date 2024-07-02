#include<cstdio>
#include<list>
#include<algorithm>

int span(int** mapa,int linha,int coluna,Lista_inimi *l,int mile,int qua_span,int numero_span);
int span_2(int** mapa,int linha,int coluna,Lista_inimi_2 *l,int mile,int qua_span,int numero_span);
int span_3(int** mapa,int linha,int coluna,Lista_inimi_3 *l,int mile,int qua_span,int numero_span);
int span_4(int** mapa,int linha,int coluna,Lista_inimi_4 *l,int mile,int qua_span,int numero_span);
int span_5(int** mapa,int linha,int coluna,Lista_inimi_5 *l,int mile,int qua_span,int numero_span);
void span_point(int** mapa,int linha,int coluna,Lista_inimi* l,Lista_inimi_2* l2,Lista_inimi_3* l3,Lista_inimi_4* l4,Lista_inimi_5* l5,int i,int j,bool reseta=false);
void span_item(BITMAP* buffer,int** mapa,int linha,int coluna);
void olhos_magico(BITMAP* m,BITMAP* buffer,int x,int y,list<bool>::iterator espera_ra,list<int>::iterator ra);
void smash(BITMAP* m,BITMAP* buffer,int x,int y,list<bool>::iterator espera_ra,list<int>::iterator ra,bool colidi=false,int direcao=0);
bool aperta(int key);



int **load_map(const char *arquivo,int *linha,int *coluna){
	
	FILE *f=fopen(arquivo,"r");
	int **matriz;
	
	if (f !=NULL){
		
		fscanf(f, "%d %d",linha,coluna);
		
		matriz= (int**) malloc ((*linha) * sizeof(int*));
		for (int i=0; i< *linha; i++)
			matriz[i]= (int*) malloc((*coluna) * sizeof(int));
		
		for (int i=0; i< *linha; i++){
			for(int j=0;j< *coluna; j++){
				
				fscanf(f,"%d",&matriz[i][j]);
				
			}
			
			
			
		}
		
		fclose(f);
	}
	
	return matriz;
	
	
}


void desenha_mapa(BITMAP* img_item,BITMAP* m,BITMAP* buffer,int **mapa,int linha,int coluna,Lista_inimi* l,Lista_inimi_2* l2,Lista_inimi_3* l3,Lista_inimi_4* l4,Lista_inimi_5* l5){
	int m_w=81,m_h=27,cal_x=0,cal_y=0;
	static int colidiu[100][100];
	static list<int>ra(100,0);
	static list<int>::iterator it=ra.begin();
	static list<bool>esperei(100,0);
	static list<bool>::iterator es_ra=esperei.begin();
	static int flag=-1;
	
	for(int i=0;i<linha;i++){
		for(int j=0;j<coluna;j++){
			
			
			if(mapa[i][j]==grama){
				
				masked_blit(m,buffer,3,2,j*72+x+370,i*20+y+11,m_w,m_h);
				
				
			
				
				if ((p1_xy+30+pos_player_x>=j*72+x+3+370) && (p1_xy+30+pos_player_x<=j*72+x+m_w+370) && ((p3_y-22)+pos_player_y>=i*20+y+2+11) && ((p3_y-22)+pos_player_y<=i*20+y+4+11)){
					//p3 lado esquerdo
					
					
						gravidade=false;
				
							for(int p=0;p<100;p++){
								for(int q=0;q<100;q++){
									colidiu[p][q]=-1;
									
									
								}
								
							}
					
					colidiu[i][j]=1;
								
						
				
				}else if(!queda){
					queda=true;
					
					
				}else if(colidiu[i][j]==1 && pular)
					colidiu[i][j]=-1;
				
				else if(colidiu[i][j]==1 && queda){
					gravidade=true;
					pular=false;
					
				}
				
			}else if(mapa[i][j]==terra){
				cal_x=159-86-1;
				cal_y=27-6;
				
					masked_blit(m,buffer,86,6,j*cal_x+375+x,i*cal_y+y-4,159,27);
				
				
				
			}else if(mapa[i][j]==terra_menor){
			
				//	masked_blit(m,buffer,86,6,j*36+x,i*21+y,123,27);	
				
				
			}else if (mapa[i][j]==inimigo_1 || mapa[i][j]==inimigo_2 || mapa[i][j]==inimigo_3 || mapa[i][j]==inimigo_4 || mapa[i][j]==inimigo_5){
				//criar um procedimento para isso ,existe um erro na numeração do inimigo onde o esperado é 20 mais pode ter um valor diferente
				
					span_point(mapa,linha,coluna,l,l2,l3,l4,l5,i,j);
			
				
				
				
				
			}else if(mapa[i][j]==terra_lado_1){
				cal_x=90;
				cal_y=21;
				
					masked_blit(m,buffer,8,40,j*cal_x+x,i*cal_y+y,75,70);
				//	rectfill(buffer,j*cal_x+x,i*cal_y+y+2,j*cal_x+x+4,i*cal_y+y+40,makecol(255,0,0));
				
				
				if (((p4_xy-60)+pos_player_x>=j*cal_x+x) && ((p4_xy-60)+pos_player_x<=j*cal_x+x+10) && ((p3_y-22)+pos_player_y>=i*cal_y+y+2) && ((p3_y-22)+pos_player_y<=i*cal_y+y+40)){
					
					
					
					stop_conte=true;
					cogela_pula=true;
					flag=terra_lado_1;
					
					x+=vel_x;
					
					
				}else if(flag==terra_lado_1){
					
					
					stop_conte=false;
					cogela_pula=false;
					flag=-1;
				
					
				}
				
				
				
				
			}else if(mapa[i][j]==terra_lado_2){
				
				cal_x=90;
				cal_y=21;
				
					masked_blit(m,buffer,87,39,j*cal_x+x-190,i*cal_y+y+1,75,70);
					//rectfill(buffer,j*cal_x+x+50,i*cal_y+y,j*cal_x+x+70,i*cal_y+y+40,makecol(255,0,0));
				
				
				if ((p1_xy+27+pos_player_x>=(j*cal_x+x+50)-190) && (p1_xy+27+pos_player_x<=(j*cal_x+x+70)-190) && ((p3_y-22)+pos_player_y>=i*cal_y+y+1) && ((p3_y-22)+pos_player_y<=i*cal_y+y+40+1)){
					
					x-=vel_x;
					
					
						stop_conte=true;
						cogela_pula=true;
						flag=terra_lado_2;
					
					
				}else if(flag==terra_lado_2){
					
					stop_conte=false;
					cogela_pula=false;
					flag=-1;
				}
					
				
				
				
				
				
			}else if(mapa[i][j]==terra_lado_3){
				
				
				cal_x=90;
				cal_y=21;
				
					masked_blit(m,buffer,167,4,j*cal_x+x,i*cal_y+y,80,40);
					//rectfill(buffer,(p4_xy-70)+pos_player_x,(p3_y-22)+pos_player_y,(p4_xy-70)+pos_player_x+20,(p3_y-22)+pos_player_y+20,makecol(255,0,0));
					//rectfill(buffer,j*cal_x+x,i*cal_y+2+y,j*cal_x+x+70,i*cal_y+y+4,makecol(0,255,0));
				
				
				if ((p1_xy+30+pos_player_x>=j*cal_x+x-4) && (p1_xy+30+pos_player_x<=j*cal_x+x+70) && ((p3_y-22)+pos_player_y>=i*cal_y+y) && ((p3_y-22)+pos_player_y<=i*cal_y+y+4)){
					
					//rectfill(buffer,p1_xy+30+pos_player_x,(p3_y-22)+pos_player_y,p1_xy+30+pos_player_x+20,(p3_y-22)+pos_player_y+20,makecol(255,0,0));
					
						gravidade=false;

							for(int p=0;p<100;p++){
								for(int q=0;q<100;q++){
									colidiu[p][q]=-1;


								}

							}

							colidiu[i][j]=1;



						}else if(!queda){
							queda=true;


						}else if(colidiu[i][j]==1 && pular)
							colidiu[i][j]=-1;

						else if(colidiu[i][j]==1 && queda){
							gravidade=true;
							pular=false;

						}
					
				//rectfill(buffer,j*cal_x+x,i*cal_y+y,j*cal_x+x+4,i*cal_y+y+40,makecol(0,0,255));
				
				if (((p4_xy-70)+pos_player_x>=j*cal_x+x) && ((p4_xy-70)+pos_player_x<=j*cal_x+x+4) && ((p3_y-22)+pos_player_y>=i*cal_y+y+2) && ((p3_y-22)+pos_player_y<=i*cal_y+y+40)){
					
					
					x+=vel_x;
					
					
				}
				
				
				
				
			}else if(mapa[i][j]==terra_lado_4){
					
				
				cal_x=90;
				cal_y=21;
				
					masked_blit(m,buffer,248,4,j*cal_x+x-190,i*cal_y+y,80,40);
				
				
				
				
					if ((p1_xy+30+pos_player_x>=j*cal_x+x-4-190) && (p1_xy+30+pos_player_x<=(j*cal_x+x+70)-190) && ((p3_y-22)+pos_player_y>=i*cal_y+y) && ((p3_y-22)+pos_player_y<=i*cal_y+y+4)){
					
					//rectfill(buffer,p1_xy+30+pos_player_x,(p3_y-22)+pos_player_y,p1_xy+30+pos_player_x+20,(p3_y-22)+pos_player_y+20,makecol(255,0,0));
					
						gravidade=false;

							for(int p=0;p<100;p++){
								for(int q=0;q<100;q++){
									colidiu[p][q]=-1;


								}

							}

							colidiu[i][j]=1;



						}else if(!queda){
							queda=true;


						}else if(colidiu[i][j]==1 && pular)
							colidiu[i][j]=-1;

						else if(colidiu[i][j]==1 && queda){
							gravidade=true;
							pular=false;

						}
					
				//rectfill(buffer,j*cal_x+x,i*cal_y+y,j*cal_x+x+4,i*cal_y+y+40,makecol(0,0,255));
				
				if (((p4_xy-70)+pos_player_x>=j*cal_x+x) && ((p4_xy-70)+pos_player_x<=j*cal_x+x+4) && ((p3_y-22)+pos_player_y>=i*cal_y+y+2) && ((p3_y-22)+pos_player_y<=i*cal_y+y+40)){
					
					
					x+=vel_x;
					
					
				}
				
				
				
				
				
				
				
			}else if(mapa[i][j]==bau){
				
				
				masked_blit(img_item,buffer,52,6,j*cal_x+x,i*cal_y+y+10,50,27);
				span_item(buffer,mapa,linha,coluna);
				
				
				
			}else if(mapa[i][j]==bloco){
				
				
				masked_blit(m,buffer,167,39,j*72+x+370+6,i*20+y+12,m_w,m_h);
				
				
			
				
				if ((p1_xy+30+pos_player_x>=j*72+x+3+370+6) && (p1_xy+30+pos_player_x<=j*72+x+m_w+370+6) && ((p3_y-22)+pos_player_y>=i*20+y+2+11) && ((p3_y-22)+pos_player_y<=i*20+y+4+11)){
					//p3 lado esquerdo
					
					
						gravidade=false;
				
							for(int p=0;p<100;p++){
								for(int q=0;q<100;q++){
									colidiu[p][q]=-1;
									
									
								}
								
							}
					
					colidiu[i][j]=1;
								
						
				
				}else if(!queda){
					queda=true;
					
					
				}else if(colidiu[i][j]==1 && pular)
					colidiu[i][j]=-1;
				
				else if(colidiu[i][j]==1 && queda){
					gravidade=true;
					pular=false;
					
				}
				
				
			}else if(mapa[i][j]==bloco_lado_1){
				cal_x=90;
				cal_y=21;
				
					masked_blit(m,buffer,167,68,j*cal_x+x,i*cal_y+y,75,70);
				//	rectfill(buffer,j*cal_x+x,i*cal_y+y+2,j*cal_x+x+4,i*cal_y+y+40,makecol(255,0,0));
				
				
				if (((p4_xy-60)+pos_player_x>=j*cal_x+x) && ((p4_xy-60)+pos_player_x<=j*cal_x+x+10) && ((p3_y-22)+pos_player_y>=i*cal_y+y+2) && ((p3_y-22)+pos_player_y<=i*cal_y+y+40)){
					
					
					
					stop_conte=true;
					cogela_pula=true;
					flag=bloco_lado_1;
					
					x+=vel_x;
					
					
				}else if(flag==bloco_lado_1){
					
					stop_conte=false;
					cogela_pula=false;
					flag=-1;
					
				}
				
				
				
				
				
				
				
			}else if(mapa[i][j]==bloco_lado_2){
					
				cal_x=90;
				cal_y=21;
				
					masked_blit(m,buffer,248,68,j*cal_x+x-190+450,i*cal_y+y+1,75,70);
					//rectfill(buffer,j*cal_x+x+50,i*cal_y+y,j*cal_x+x+70,i*cal_y+y+40,makecol(255,0,0));
				
				
				if ((p1_xy+27+pos_player_x>=(j*cal_x+x+50)-190+450) && (p1_xy+27+pos_player_x<=(j*cal_x+x+70)-190+450) && ((p3_y-22)+pos_player_y>=i*cal_y+y+1) && ((p3_y-22)+pos_player_y<=i*cal_y+y+40+1)){
					
					x-=vel_x;
					
					
						stop_conte=true;
						cogela_pula=true;
						flag=bloco_lado_2;
					
					
				}else if(flag==bloco_lado_2){
					
					stop_conte=false;
					cogela_pula=false;
					flag=-1;
				}
					
				
				
				
				
			}else if(mapa[i][j]==bloco_lado_3){
						
				
				cal_x=90;
				cal_y=21;
				
					masked_blit(m,buffer,248,40,j*cal_x+x,i*cal_y+y+1,78,40);
					//rectfill(buffer,(p4_xy-70)+pos_player_x,(p3_y-22)+pos_player_y,(p4_xy-70)+pos_player_x+20,(p3_y-22)+pos_player_y+20,makecol(255,0,0));
					//rectfill(buffer,j*cal_x+x,i*cal_y+2+y,j*cal_x+x+70,i*cal_y+y+4,makecol(0,255,0));
				
				
				if ((p1_xy+30+pos_player_x>=j*cal_x+x-4) && (p1_xy+30+pos_player_x<=j*cal_x+x+70) && ((p3_y-22)+pos_player_y>=i*cal_y+y) && ((p3_y-22)+pos_player_y<=i*cal_y+y+4)){
					
					//rectfill(buffer,p1_xy+30+pos_player_x,(p3_y-22)+pos_player_y,p1_xy+30+pos_player_x+20,(p3_y-22)+pos_player_y+20,makecol(255,0,0));
					
						gravidade=false;

							for(int p=0;p<100;p++){
								for(int q=0;q<100;q++){
									colidiu[p][q]=-1;


								}

							}

							colidiu[i][j]=1;



						}else if(!queda){
							queda=true;


						}else if(colidiu[i][j]==1 && pular)
							colidiu[i][j]=-1;

						else if(colidiu[i][j]==1 && queda){
							gravidade=true;
							pular=false;

						}
					
				//rectfill(buffer,j*cal_x+x,i*cal_y+y,j*cal_x+x+4,i*cal_y+y+40,makecol(0,0,255));
				
				if (((p4_xy-70)+pos_player_x>=j*cal_x+x) && ((p4_xy-70)+pos_player_x<=j*cal_x+x+4) && ((p3_y-22)+pos_player_y>=i*cal_y+y+2) && ((p3_y-22)+pos_player_y<=i*cal_y+y+40)){
					
					
					x+=vel_x;
					//rectfill(buffer,j*cal_x+x,i*cal_y+y,j*cal_x+x+20,i*cal_y+y+20,makecol(255,0,0));
					
				}
				
					if (((p4_xy-70)+pos_player_x>=j*cal_x+x-20) && ((p4_xy-70)+pos_player_x<=j*cal_x+x+4) && ((p3_y-22)+pos_player_y>=i*cal_y+y) && ((p3_y-22)+pos_player_y<=i*cal_y+y+20)){
					
						if(agarra){
							
							agarra=false;
							pos_player_x+=20;
							pos_player_y-=20;
							gravidade=true;
							mante_agarra=false;
							
							
							
						}
						//rectfill(buffer,j*cal_x+x,i*cal_y+y,j*cal_x+x+20,i*cal_y+y+20,makecol(255,0,0));
						
					}
				
				
				
				
				
				
				
				
				
				
			}else if(mapa[i][j]==bloco_lado_4){
						
				
				cal_x=90;
				cal_y=21;
				
					masked_blit(m,buffer,327,40,j*cal_x+x-190+450,i*cal_y+y+2,80,40);
				
				
				
				
					if ((p1_xy+30+pos_player_x>=j*cal_x+x-4-190+450) && (p1_xy+30+pos_player_x<=(j*cal_x+x+70)-190+450) && ((p3_y-22)+pos_player_y>=i*cal_y+y) && ((p3_y-22)+pos_player_y<=i*cal_y+y+4)){
					
					//rectfill(buffer,p1_xy+30+pos_player_x,(p3_y-22)+pos_player_y,p1_xy+30+pos_player_x+20,(p3_y-22)+pos_player_y+20,makecol(255,0,0));
					
						gravidade=false;

							for(int p=0;p<100;p++){
								for(int q=0;q<100;q++){
									colidiu[p][q]=-1;


								}

							}

							colidiu[i][j]=1;



						}else if(!queda){
							queda=true;


						}else if(colidiu[i][j]==1 && pular)
							colidiu[i][j]=-1;

						else if(colidiu[i][j]==1 && queda){
							gravidade=true;
							pular=false;

						}
					
				//rectfill(buffer,j*cal_x+x,i*cal_y+y,j*cal_x+x+4,i*cal_y+y+40,makecol(0,0,255));
				
				if (((p4_xy-70)+pos_player_x>=j*cal_x+x+70-190+450) && ((p4_xy-70)+pos_player_x<=j*cal_x+x+80-190+450) && ((p3_y-22)+pos_player_y>=i*cal_y+y+2) && ((p3_y-22)+pos_player_y<=i*cal_y+y+40)){
					
					
					x+=vel_x;
				//	rectfill(buffer,j*cal_x+x+70-190+450,i*cal_y+y,j*cal_x+x+20-190+450,i*cal_y+y+20,makecol(255,0,0));
					
				}
				
				
				if (((p4_xy-70)+pos_player_x>=j*cal_x+x+50-190+450) && ((p4_xy-70)+pos_player_x<=j*cal_x+x+120-190+450) && ((p3_y-22)+pos_player_y>=i*cal_y+y+2) && ((p3_y-22)+pos_player_y<=i*cal_y+y+40)){
					
					
					
					
					if(agarra){
							
							agarra=false;
							pos_player_x-=20;
							pos_player_y-=40;
							gravidade=true;
							mante_agarra=false;
							
							
							
						}
						//rectfill(buffer,j*cal_x+x+70-190+450,i*cal_y+y,j*cal_x+x+20-190+450,i*cal_y+y+20,makecol(255,0,0));
						
					
					
				}
				
				
				
				
				
				
			}else if (mapa[i][j]==bloco_vivo){
				
				
				cal_x=69;
				cal_y=21;
				
				
					advance(es_ra,j);
					advance(it,j);
					olhos_magico(m,buffer,j*cal_x+x-190+587,i*cal_y+y-3,es_ra,it);
					it=ra.begin();
					es_ra=esperei.begin();
				
				
				
				
			}
			
		}
		
	}
	
	
	
	
	
}


void smash(BITMAP* m,BITMAP* buffer,int x,int y,list<bool>::iterator espera_ra,list<int>::iterator ra,bool colidi,int direcao){
	list<int>bloco(10,0);
	int dupla=0;
	
		if(!colidi)
			masked_blit(m,buffer,327,68,x,y,70,40);
		else if(direcao==0){

			if(!*espera_ra || *ra>=0){ *ra-=5; *espera_ra=false;}
			
			
			masked_blit(m,buffer,327,68,x,y+(*ra),70,40);

			for(auto ip:bloco){
				
				dupla+=20;
				ip=dupla;
				masked_blit(m,buffer,327,68,x,y+(*ra)+ip,70,40);
				
			}
			if (*ra<-300 || *espera_ra){ *ra+=1;*espera_ra=true;}

		}
	
	
}

void olhos_magico(BITMAP* m,BITMAP* buffer,int x,int y,list<bool>::iterator espera_ra,list<int>::iterator ra){
//	static int eye_x=0,eye_y=0;
	static  bool esq_eye=false;
	
	if ((pos_player_x+p4_xy-22>=x && pos_player_x+p4_xy-22<=x+200 && pos_player_y+p4_xy-22>=y-900 && pos_player_y+p4_xy-22<=y+1000) || *ra!=0){
		
		smash(m,buffer,x,y,espera_ra,ra,true);
		
		if (pos_player_x+p4_xy-22<=x+100){
			
			if(pos_player_y+p4_xy-22>y-100){
				
				masked_blit(m,buffer,399,87,x+10,y+10+(*ra),10,20);
				masked_blit(m,buffer,399,87,x+40,y+10+(*ra),10,20);
				
			}else{
			
				masked_blit(m,buffer,399,87,x+10,y+5+(*ra),10,20);
				masked_blit(m,buffer,399,87,x+40,y+5+(*ra),10,20);
				
			}
			esq_eye=true;
		
		}else if (pos_player_x+p1_xy-22>x+40 && !esq_eye){
			
			if(pos_player_y+p4_xy-22>y-100){
				
				masked_blit(m,buffer,399,87,x+20,y+10+(*ra),10,20);
				masked_blit(m,buffer,399,87,x+50,y+10+(*ra),10,20);
				
			}else{
			
				masked_blit(m,buffer,399,87,x+20,y+5+(*ra),10,20);
				masked_blit(m,buffer,399,87,x+50,y+5+(*ra),10,20);
				
			}
		}else
			esq_eye=false;
		
		
		
	}else{
	
		smash(m,buffer,x,y,espera_ra,ra,false);
		masked_blit(m,buffer,399,87,x+15,y+10,10,20);
		masked_blit(m,buffer,399,87,x+45,y+10,10,20);
		
	}
	
}

void fecha_mapa(int **m,int linha){
	
	for (int i=0; i< linha; i++){
		
		free(m[i]);
	}
	free(m);
}

void meu_item(BITMAP* img_item,BITMAP* buffer){
	
	if(inven[0]==1)
		masked_blit(img_item,buffer,0,0,100,20,23,11);
	
	if(inven[1]==2)
		masked_blit(img_item,buffer,0,59,127,20,32,30);
	
	if(inven[2]==3)
		masked_blit(img_item,buffer,0,101,150,20,105,40);
	
	if(inven[3]==4)
		masked_blit(img_item,buffer,0,143,180,21,43,40);
	
	
}


void seleciona_item(BITMAP* img_player,BITMAP* img_item,BITMAP* buffer,int mile){
	static int sel=0,mov=mile,reduzia=0,pula_frame=0,correcao=0;
	
	if((inven[0]==1 && aperta(KEY_1)) || sel==1){
		
		if(mile - mov >= 300 && andando){
			
			
			reduzia-=8;
		
		if(reduzia<-30)reduzia=0;
			mov=mile;
			
			
		}else if(!andando)
			reduzia=0;
			
		
		
		if(lado==0){
			
			if(!atack_frame)
				masked_blit(img_item,buffer,0,0,pos_player_x+29+reduzia,pos_player_y+56,23,11);
			
			
			
		}else if(lado==1){
			
			if(!atack_frame)
				masked_blit(img_item,buffer,108,0,pos_player_x+10+reduzia,pos_player_y+56,23,29);
			
			
		}
		
		rectfill(buffer,hit_x,hit_y,hit_x+10,hit_y+10,makecol(255,0,0));
		
		if(espera_atack){espera_atack=false;hit_x=0;hit_y=0;}
		
		if (aperta(KEY_H) || (stop_frame && atack_frame)){
			stop_frame=true;
			atack_frame=true;
			
			
			
			if(lado==1)
				frame_v=512;
			else if(lado==0)
				frame_v=449;
			
			frame_atual=(mile/800) % 2;
			if(frame_atual==1){correcao=25;pula_frame=62;} else if(frame_atual==0){correcao=0;pula_frame=0;}
			masked_blit(img_player,buffer,pula_frame,frame_v,pos_player_x-2+correcao,pos_player_y+35,37,40);
			
			
			if(lado==0){
				
				
			if(frame_atual==1)
					masked_blit(img_item,buffer,0,0,pos_player_x+38+reduzia,pos_player_y+50,23,11);
				
				else if(frame_atual==0)
					masked_blit(img_item,buffer,0,0,pos_player_x+29+reduzia,pos_player_y+50,23,11);
				
				
				
			}
			
			if(lado==1){
				
				
			if(frame_atual==1)
					masked_blit(img_item,buffer,108,0,pos_player_x-reduzia,pos_player_y+50,23,11);
				
				else if(frame_atual==0)
					masked_blit(img_item,buffer,108,0,pos_player_x+reduzia,pos_player_y+50,23,11);
				
				
				
			}
			
			
			if(correcao==25){
				
				if(lado==0){
					
					hit_x=pos_player_x+50;
					hit_y=pos_player_y+50;
				
				}else if(lado==1){
					
					hit_x=pos_player_x;
					hit_y=pos_player_y+50;
					
					
				}
				
				frame_atual=0;
				stop_frame=false;
				atack_frame=false;
				espera_atack=true;
				
				if(lado==0)
				frame_v=0;
				else if(lado==1)
					frame_v=82;
				
				
				
			}
			
			
			
			
		}
		
		sel=1;
		
	}
	
	if((inven[1]==2 && aperta(KEY_2)) || sel==2){
		
		if(mile - mov >= 300 && andando){
			
			
			reduzia-=8;
		
		if(reduzia<-30)reduzia=0;
			mov=mile;
			
			
		}else if(!andando)
			reduzia=0;
			
		masked_blit(img_item,buffer,0,59,pos_player_x+29+reduzia,pos_player_y+46,32,30);
		
		if (aperta(KEY_H)){//melhor um procedimento
			bomba=true;
			
		
		}
		
		if(qtd_bomb<=0)sel=0;else sel=2;
		
	}
	
	
	if((inven[2]==3 && aperta(KEY_3)) || sel==3){
		
		if(mile - mov >= 300 && andando){
			
			
			reduzia-=8;
		
		if(reduzia<-30)reduzia=0;
			mov=mile;
			
			
		}else if(!andando)
			reduzia=0;
			
		masked_blit(img_item,buffer,0,101,pos_player_x+24+reduzia,pos_player_y+46,105,40);
		
		if (aperta(KEY_H)){
			
			tocou=true;
			
			
		}
		
		sel=3;
		
	}
	
	
	if((inven[3]==4 && aperta(KEY_4)) || sel==4){
		
		if(mile - mov >= 300 && andando){
			
			
			reduzia-=8;
		
		if(reduzia<-30)reduzia=0;
			mov=mile;
			
			
		}else if(!andando)
			reduzia=0;
			
		masked_blit(img_item,buffer,0,143,pos_player_x+16+reduzia,pos_player_y+53,43,40);
		
		if (aperta(KEY_H)){
			
			if(agarra==false)
				agarra=true;
			else
				agarra=false;
			
			
		}
		
		sel=4;
		
	}
	
	
	
	
	
}


void adiciona_item(int slot,int pos){
	
	
	if((p1_xy+pos_player_x<=pos_x_item[slot][pos]+x+30) && (p1_xy+pos_player_x>=pos_x_item[slot][pos]+x-30) &&
		((p3_y-22)+pos_player_y>=(pos_y_item[slot][pos]+y-30)+10) && ((p3_y-22)+pos_player_y<=pos_y_item[slot][pos]+y+30+10) && aperta(KEY_S)){

			switch (slot){//aqui é adicionado o item(slot) na posição do inventário


				case 1:
					inven[0]=slot;
					break;
				case 2:
					inven[1]=slot;
					qtd_bomb+=1;
					break;
				case 3:
					inven[2]=slot;
					break;
				case 4:
					inven[3]=slot;
					break;


			}
		
			//a var pos do item registrar item(slot) dentro da posição em relação ao mapa, o valor 0 sinaliza para deleta o item
			pos_x_item[slot][pos]=0;
			pos_x_item[slot][pos]=0;
		
	}
	
	
}


void mostra_item(BITMAP* img_item,BITMAP* buffer){
	
	
	for (int i=0;i<10;i++){
		
		
		if(pos_x_item[1][i]!=0 && pos_x_item[1][i]!=-1)
		masked_blit(img_item,buffer,0,0,pos_x_item[1][i]+x,pos_y_item[1][i]+y,23,11);
		adiciona_item(1,i);
	
		
		
	}
	
	
	for (int i=0;i<10;i++){
		
		
		if(pos_x_item[2][i]!=0 && pos_x_item[2][i]!=-1)
		masked_blit(img_item,buffer,0,31,pos_x_item[2][i]+x,pos_y_item[2][i]+y-29,26,76);
		adiciona_item(2,i);
	
		
		
	}
	
	for (int i=0;i<10;i++){
		
		
		if(pos_x_item[3][i]!=0 && pos_x_item[3][i]!=-1)
		masked_blit(img_item,buffer,0,102,pos_x_item[3][i]+x,pos_y_item[3][i]+y,37,30);
		adiciona_item(3,i);
	
		
		
	}
	
	
	for (int i=0;i<10;i++){
		
		
		if(pos_x_item[4][i]!=0 && pos_x_item[4][i]!=-1)
		masked_blit(img_item,buffer,0,142,pos_x_item[4][i]+x,pos_y_item[4][i]+y,42,158);
		adiciona_item(4,i);
	
		
		
	}
}


void chama_item(int i,int j,int valor){
	
	for(int t=0;t<10;t++){
		
		if(pos_x_item[valor][t]==0){
			
			if(valor==1){
			
				pos_x_item[valor][t]=j*70+10;
				pos_y_item[valor][t]=i*21;
				
				
				
			}
			
			if(valor==2){
			
				pos_x_item[valor][t]=j*70+10;
				pos_y_item[valor][t]=i*21;
				
				
				
			}
			
			
			if(valor==3){
			
				pos_x_item[valor][t]=j*70+10;
				pos_y_item[valor][t]=i*21;
				
				
				
			}
			
			
			if(valor==4){
			
				pos_x_item[valor][t]=j*70+10;
				pos_y_item[valor][t]=i*21;
				
				
				
			}
		
			
			
		}
	
			
			if(t<10 && pos_x_item[valor][t]!=0 && pos_x_item[valor][t]!=-1){
				
				
				pos_x_item[valor][t+1]=0;
				exit;
				
			}
		
	}
	
	
	
}


void gera_item(int** mapa,int i,int j){//lembra de remover o comentario daqui
	
	
	srand(time(NULL));
	//valor=rand() % 5;
	valor=2;
	chama_item(i,j,valor);
	mapa[i][j]=0;
	
	
}


void span_item(BITMAP* buffer,int** mapa,int linha,int coluna){
	int cal_x=71-51,cal_y=37-9;
	
	for(int i=0;i<linha;i++){
		for(int j=0;j<coluna;j++){
			
			if(mapa[i][j]==bau){
				
				//rectfill(buffer,j*70+x,i*22+y,j*70+30+x,i*22+y+30,makecol(255,0,0));
				
				
				if((p1_xy+pos_player_x<=j*70+x) && (p1_xy+pos_player_x>=j*70+x-30) && ((p3_y-22)+pos_player_y>=(i*22+y-30)+10) && ((p3_y-22)+pos_player_y<=i*22+y+30+10)){
					
					
					gera_item(mapa,i,j);
					
				}
				
				
			}
			
			
		}
		
	}
	
	
	
}


void span_point(int** mapa,int linha,int coluna,Lista_inimi* l,Lista_inimi_2* l2,Lista_inimi_3* l3,Lista_inimi_4* l4,Lista_inimi_5* l5,int i,int j,bool reseta){
	static int tempo=mile,numero_span=19,pula_inimigo=0;
	
	
//problema parcialmente resolvido
	
	if(qua_span==0){
		
		numero_span++;
		parou_qua=false;
		
	}
	
	if(!parou_qua){
		
		for(int p=0;p<linha;p++){
			for(int q=0;q<coluna;q++){

				if(mapa[p][q]==numero_span)
					qua_span++;


			}

		}
	
	}
	parou_qua=true;
	

	
	if(qua_span>0){
		
		qua_span=span(mapa,linha,coluna,l,mile,qua_span,numero_span);
		qua_span=span_2(mapa,linha,coluna,l2,mile,qua_span,numero_span);
		qua_span=span_3(mapa,linha,coluna,l3,mile,qua_span,numero_span);
		qua_span=span_4(mapa,linha,coluna,l4,mile,qua_span,numero_span);
		qua_span=span_5(mapa,linha,coluna,l5,mile,qua_span,numero_span);
		
		
	}
}



int span(int** mapa,int linha,int coluna,Lista_inimi *l,int mile,int qua_span,int numero_span){
	static int tempo=mile,i=-1,j=-1,p=-1,q=-1,qua_atual=0,repita=0;

	if(numero_span==20){
		if(numero_span==20 || numero_span==-1){

			if(qua_atual<qua_span){

				if(mile - tempo >= 1000){

					for( i=0;i<linha;i++){
						for( j=0;j<coluna;j++){

							if(mapa[i][j]==20){

								if((p<=i && q<=j) || (i==-1 && j==-1)){

									No_inimi *novo= (No_inimi*) malloc(sizeof(No_inimi));
									novo->inimi= new Enemy_1(mapa,linha,coluna,j*10-240,i*80+1200,mile);
									novo->prox=l->inicio;
									l->inicio=novo;

									if(repita>=2){

									p=i;
									q=j;
									qua_atual++;
										repita=0;
									}
									repita++;
									break;

								}

							}

						}

					}

				tempo=mile;

				}

			}else if(qua_atual==qua_span){
				parou_qua=false;
				return qua_span=0;
				//return 21;

			}


		}
	
}
	
	//if(numero_span==20)
//	aguarde=-1;
	
	
		return qua_span;
	
	
	
}


int span_2(int** mapa,int linha,int coluna,Lista_inimi_2 *l,int mile,int qua_span,int numero_span){
static int tempo=mile,i=-1,j=-1,p=-1,q=-1,qua_atual=0;

	if( numero_span==21){
		
		if(numero_span==21 || numero_span==-1){

			if(qua_atual<qua_span){

				if(mile - tempo >= 1000){

					for( i=0;i<linha;i++){
						for( j=0;j<coluna;j++){

							if(mapa[i][j]==21){

								if((p<=i && q<=j) || (i==-1 && j==-1)){	


										No_inimi_2 *novo= (No_inimi_2*) malloc(sizeof(No_inimi_2));
										novo->inimi= new Enemy_2(mapa,linha,coluna,j*10,i*80,mile);
										novo->prox=l->inicio;
										l->inicio=novo;



									p=i;
									q=j;
									qua_atual++;
									break;

								}

							}

						}

					}

				tempo=mile;

				}

			}else if(qua_atual==qua_span){
				parou_qua=false;
				return qua_span=0;
			//	return 22;

			}


		}
		
	}

		return qua_span;
	
	
	
	
}



int span_3(int** mapa,int linha,int coluna,Lista_inimi_3 *l,int mile,int qua_span,int numero_span){
static int tempo=mile,i=-1,j=-1,p=-1,q=-1,qua_atual=0;

	if( numero_span==22){
		
		if(numero_span==22 || numero_span==-1){

			if(qua_atual<qua_span){

				if(mile - tempo >= 1000){

					for( i=0;i<linha;i++){
						for( j=0;j<coluna;j++){

							if(mapa[i][j]==22){

								if((p<=i && q<=j) || (i==-1 && j==-1)){	


										No_inimi_3 *novo= (No_inimi_3*) malloc(sizeof(No_inimi_3));
										novo->inimi= new Enemy_3(mapa,linha,coluna,j*10+140,i*80+60,mile);
										novo->prox=l->inicio;
										l->inicio=novo;



									p=i;
									q=j;
									qua_atual++;
									break;

								}

							}

						}

					}

				tempo=mile;

				}

			}else if(qua_atual==qua_span){
				parou_qua=false;
				return qua_span=0;
				//return 23;

			}


		}
		
	}

		return qua_span;
	
	
	
	
}


int span_4(int** mapa,int linha,int coluna,Lista_inimi_4 *l,int mile,int qua_span,int numero_span){
static int tempo=mile,i=-1,j=-1,p=-1,q=-1,qua_atual=0;

	if( numero_span==23){
		
		if(numero_span==23 || numero_span==-1){

			if(qua_atual<qua_span){

				if(mile - tempo >= 1000){

					for( i=0;i<linha;i++){
						for( j=0;j<coluna;j++){

							if(mapa[i][j]==23){

								if((p<=i && q<=j) || (i==-1 && j==-1)){	


										No_inimi_4 *novo= (No_inimi_4*) malloc(sizeof(No_inimi_4));
										novo->inimi= new Enemy_4(mapa,linha,coluna,j*10+140,i*80+60,mile);
										novo->prox=l->inicio;
										l->inicio=novo;



									p=i;
									q=j;
									qua_atual++;
									break;

								}

							}

						}

					}

				tempo=mile;

				}

			}else if(qua_atual==qua_span){
				parou_qua=false;
				return qua_span=0;
				//return 24;

			}


		}
		
	}

		return qua_span;
	
	
	
	
}

int span_5(int** mapa,int linha,int coluna,Lista_inimi_5 *l,int mile,int qua_span,int numero_span){//existe um erro onde objeto em linhas iguais ou colunas ,impedi de espanar
static int tempo=mile,i=-1,j=-1,p=-1,q=-1,qua_atual=0;

	if( numero_span==24){
		
		if(numero_span==24 || numero_span==-1){

			if(qua_atual<qua_span){

				if(mile - tempo >= 1000){

					for( i=0;i<linha;i++){
						for( j=0;j<coluna;j++){

							if(mapa[i][j]==24){

								if((i==-1 && j==-1) || (p<i && q<j) || ((p<i && q==j) || (p==i && q<j))){	


										No_inimi_5 *novo= (No_inimi_5*) malloc(sizeof(No_inimi_5));
										novo->inimi= new Enemy_5(mapa,linha,coluna,j*10+220,i*80-460,mile);
										novo->prox=l->inicio;
										l->inicio=novo;



									p=i;
									q=j;
									qua_atual++;
									//break;

								}

							}

						}

					}

				tempo=mile;

				}

			}else if(qua_atual==qua_span){
				parou_qua=false;
				return qua_span=0;
				//return 25;

			}


		}
		
	}

		return qua_span;
	
	
	
	
}




void leva_golpe(){
	
	if((pos_player_x>500)&&(conte<=500))pos_player_x--;else if(pos_player_x>500)pos_player_x--;
	
	
	if(golpe>0){
		
		if(!lado){
			

			x+=150;
			pos_player_y-=50;
			conte-=150;
			if(conte<0){conte=0;x=-370;}
			
			
		}else{
			
			x-=150;
			pos_player_y-=50;
			conte+=150;
			
		}
		
		vidas--;
		golpe--;
	}
	
	
}









void atualiza_tecla(){
	
	
	for (int i=0;i<=KEY_MAX;i++){
		
		tecla_ante[i]=key[i];
		
		
	}
	poll_keyboard();
	
	
}

bool aperta(int tecla){
	
	if ((!key[tecla])&&(tecla_ante[tecla])){
		
		return true;
		
	}else{
		
		return false;
	}
	
	
}
bool segura(int tecla){
	
	if ((key[tecla])&&(tecla_ante[tecla])){
		
		return true;
		
	}else{
		
		return false;
	}
	
	
	
	
}
bool solta(int tecla){
	
	if ((key[tecla])&&(!tecla_ante[tecla])){
		
		return true;
		
	}else{
		
		return false;
	}
	
	
	
	
	
	
	
}


void escala(){//existe um problema na escalada
	 
	
	if((agarra && cogela_pula) || mante_agarra){
		
		if(lado==1 || lado==0){
			
			if (lado==0)
				ajuste=50;
			else
				ajuste=0;
			
			
			if(segura(KEY_W)){
				
				pos_player_y-=vel_y;
				mante_agarra=true;
				
				
				if(lado==1)
					frame_v=638;
				frame_atual=(mile/300) % 2;
				
			//	if(frame_atual==1 && lado==1)pos_player_x+=0.5; else pos_player_x-=0.5;
			//	if(frame_atual==1 && lado==0)pos_player_x+=1.5; else pos_player_x-=0.5;
			}
			
			
			if(segura(KEY_S)){
				
				
				pos_player_y+=vel_y;
				mante_agarra=true;
				
					if(lado==0)
						frame_v=580;
					frame_atual=(mile/300) % 2;
			//	if(frame_atual==1 && lado==1)pos_player_x+=0.5; else pos_player_x-=0.5;
			//	if(frame_atual==1 && lado==0)pos_player_x+=0.5; else pos_player_x-=0.5;
				
			}
			
			
			if(segura(KEY_A) && lado==0){
				
				mante_agarra=false;
				agarra=false;
				cogela_pula=false;
				gravidade=true;
				dont_move=true;
				
			}else if(segura(KEY_D) && lado==1){
				
				mante_agarra=false;
				agarra=false;
				cogela_pula=false;
				gravidade=true;
				dont_move=true;
				
			}
			
		}
		
		
	}
	
	dont_move=false;
	
	
	
}


void flauta(){
	static int tempo_m=mile;
	
	if(tocou){
		
		stop_frame=true;
		cogela_pula=true;
		sexy=true;
		
		
		
	}
	
	if(mile - tempo_m >= 400 && tocou){
		
		stop_frame=false;
		cogela_pula=false;
		tocou=false;
		
		
		
		tempo_m=mile;
			
		}
	
	
}

bool  meu_status(BITMAP* buffer,FONT* fonte,bool fgame){
	
	
	textprintf_ex(buffer,fonte,SCREEN_W/2,100,makecol(255,255,255),30,"%d LIFE",hp);
	textprintf_ex(buffer,fonte,SCREEN_W/2+150,100,makecol(255,255,255),30,"%d BOMB",qtd_bomb);
	if(hp<=0){cena=game_over;return fgame=true;}else return fgame=false;
	
	
}


void player_control(BITMAP* buffer,BITMAP* player){
	frame=137/4;
	static bool stop_frame_aux=false;
	static int tempo=mile;
	
	leva_golpe();
	escala();
	flauta();
	
	
	if(!dont_move){
	
		if(conte>50){

			if (segura(KEY_D)){
				if(!stop_frame){


					frame_v=0;

					frame_atual= (mile/300) % 4;


				if(!stop_conte)
				conte++;
				x-=vel_x;
				andando=true;
				lado=0;

				}

			}else if (segura(KEY_A)){
				if(!stop_frame){


					frame_v=82;

					frame_atual= (mile/300) % 4;

				if(!stop_conte)
				conte--;
				x+=vel_x;
				andando=true;
				lado=1;

				}

					}else
						andando=false;

		}else{

			if(segura(KEY_D)){

				if(!stop_frame){


					frame_v=0;

					frame_atual= (mile/300) % 4;



					if(!stop_conte)
					conte++;
					pos_player_x+=vel_x;
					andando=true;
					lado=0;

				}
			}else if(segura(KEY_A)){

				if(!stop_frame){


					frame_v=82;

					frame_atual= (mile/300) % 4;



					if(!stop_conte)
					conte--;
					pos_player_x-=vel_x;
					andando=true;
					lado=1;


					}
			}else
				andando=false;


	}
	
		
	}
	
	if (!segura(KEY_A) && !segura(KEY_D) && !pular && !mante_agarra) frame_atual=0;
	
	if(!cogela_pula and !mante_agarra){
		
	
		if((solta(KEY_W) && !gravidade && limite) || (stop_frame && !atack_frame)){


			stop_frame=true;

			if(!atack_frame){

				if(frame_v==82)
					frame_v=327;
				else if(frame_v==0)
					frame_v=194;

			}


			frame_atual=0;

			if(aperta(KEY_W)){

				altura=pos_player_y-250;
				limite=false;
				pular=true;
				frame_atual=0;
				stop_frame=false;
				stop_frame_aux=true;


			}

		}

		if(!limite && !gravidade){



			if (stop_frame_aux){

			//	stop_frame_aux=true;
				pos_player_y-=vel_y;
				vel_y+=ace_y;
				frame_atual=1;

			}



			if(vel_y>10)vel_y=10;
			if (pos_player_y<altura)
				limite=true;

		}

		if(limite && pular){
			gravidade=true;
			pular=false;
			//stop_frame=false;
			frame_atual=0;


		}

		if (gravidade && !pular){


			if(frame_v==327)
				frame_v=82;
			else if(frame_v==194)
				frame_v=0;


			pos_player_y+=vel_y;
			vel_y-=ace_y;

			if(vel_y<5)vel_y=5.0;

		}

	
	
	}
	
	
	if(!atack_frame)
		masked_blit(player,buffer,(frame + 10) * frame_atual,frame_v,pos_player_x,pos_player_y,40,100-ajuste);
		p1_xy=0;
		p2_x=100;
		p3_y=100;
		p4_xy=100;
	
}

void lanca_bomba(BITMAP* img_item,BITMAP* buffer,int mile){
	static int tic=mile,pos_temp=0,fracao=mile;
	
	if(bomba){
		if(lado_atual_bomb==-1){
			
			lado_atual_bomb=lado;
			pos_temp=pos_player_x+29;
			
		}
		
		if(lado_atual_bomb==0)
				pos_x_bomb+=5;
			if(lado_atual_bomb==1)
				pos_x_bomb-=5;
		
		
		if(pos_y_bomb==0)
			pos_y_bomb+=pos_player_y+46+y-300;
		
		
				if(pos_x_bomb>400){
					
					bomba=false;
					//pos_x_bomb=0;
					tempo_bomb=true;
					pos_x_bomb+=pos_temp;
					//pos_y_bomb+=pos_player_y+46;
					
				}
		
				if(pos_x_bomb<-400){

							bomba=false;
							//pos_x_bomb=0;
							tempo_bomb=true;
							pos_x_bomb=pos_temp-400;
							//pos_y_bomb+=pos_player_y+46;

						}
				
				masked_blit(img_item,buffer,0,59,pos_temp+pos_x_bomb,pos_y_bomb,32,30);
			
	
	}
	
	if(tempo_bomb){
		
		if(mile - tic >=1000){
			
				masked_blit(img_item,buffer,0,59,pos_x_bomb,pos_y_bomb,32,30);
			
			if(mile - tic >=1800){
				
					masked_blit(img_item,buffer,43,61,pos_x_bomb,pos_y_bomb,39,39);
				
				
				hit_x_bomb=pos_x_bomb;
				hit_y_bomb=pos_y_bomb;
				pos_x_bomb=0;
				pos_y_bomb=0;
				lado_atual_bomb=-1;
				tempo_bomb=false;
				tic=mile;
			}
		//	break;
			
			//tic=mile;
		}else
		masked_blit(img_item,buffer,0,59,pos_x_bomb+x,pos_y_bomb,32,30);
			
		

		
	}
	
	
		if(hit_x_bomb>=0 || hit_x_bomb == pos_temp-400){
			
			if(mile -  fracao >=2700){
				
				
				hit_x_bomb=-2000;
				hit_y_bomb=-2000;
				qtd_bomb--;
				if(qtd_bomb<=0)inven[1]=-1;
				
				fracao=mile;
				
			}
			
			
			
			
		}
	
}



Lista_inimi *create_lista(){//cria a lista
	
	Lista_inimi* l= (Lista_inimi*) malloc(sizeof(Lista_inimi));
	
	l->inicio=NULL;
	
	return l;
	
	
}


void destroy_inimi (Enemy_1 *i){//recebe o objeto
	
	free(i);
	
	
}

void destroy_lista(Lista_inimi *l){
	
	No_inimi *aux;
	
	while (l->inicio != NULL){
		
		aux= l->inicio;
		l->inicio =l->inicio->prox;
		destroy_inimi(aux->inimi);
		free(aux);
		
	}
	
	
}



void update_lista(Lista_inimi *l,BITMAP* img_inimi,BITMAP* buffer,int mile){
	
	No_inimi *aux=l->inicio;
	No_inimi *aux2=l->inicio;
	
	while (aux != NULL){
		
		if (aux->inimi->ativo){
			
			aux->inimi->update(img_inimi,buffer,mile);
			aux2=aux;
			aux=aux->prox;
			
		}else{
			if (aux2==aux){
				l->inicio=l->inicio->prox;
				destroy_inimi(aux->inimi);
				free(aux);
				aux2=aux=l->inicio;
				
				
			}else{
				
				aux2->prox=aux->prox;
				destroy_inimi(aux->inimi);
				free(aux);
				aux=aux2->prox;
				
			}
			
			
			
		}
		
		
		
	}
	
	
}





Lista_inimi_2 *create_lista_2(){//cria a lista
	
	Lista_inimi_2* l= (Lista_inimi_2*) malloc(sizeof(Lista_inimi_2));
	
	l->inicio=NULL;
	
	return l;
	
	
}


void destroy_inimi_2 (Enemy_2 *i){//recebe o objeto
	
	free(i);
	
	
}

void destroy_lista_2(Lista_inimi_2 *l){
	
	No_inimi_2 *aux;
	
	while (l->inicio != NULL){
		
		aux= l->inicio;
		l->inicio =l->inicio->prox;
		destroy_inimi(aux->inimi);
		free(aux);
		
	}
	
	
}



void update_lista_2(Lista_inimi_2 *l,BITMAP* img_inimi,BITMAP* buffer,int mile){
	
	No_inimi_2 *aux=l->inicio;
	No_inimi_2 *aux2=l->inicio;
	
	while (aux != NULL){
		
		if (aux->inimi->ativo){
			
			aux->inimi->update(img_inimi,buffer,mile);
			aux2=aux;
			aux=aux->prox;
			
		}else{
			if (aux2==aux){
				l->inicio=l->inicio->prox;
				destroy_inimi(aux->inimi);
				free(aux);
				aux2=aux=l->inicio;
				
				
			}else{
				
				aux2->prox=aux->prox;
				destroy_inimi(aux->inimi);
				free(aux);
				aux=aux2->prox;
				
			}
			
			
			
		}
		
		
		
	}
	
	
}





Lista_inimi_3 *create_lista_3(){//cria a lista
	
	Lista_inimi_3* l= (Lista_inimi_3*) malloc(sizeof(Lista_inimi_3));
	
	l->inicio=NULL;
	
	return l;
	
	
}


void destroy_inimi_3 (Enemy_3 *i){//recebe o objeto
	
	free(i);
	
	
}

void destroy_lista_3(Lista_inimi_3 *l){
	
	No_inimi_3 *aux;
	
	while (l->inicio != NULL){
		
		aux= l->inicio;
		l->inicio =l->inicio->prox;
		destroy_inimi_3(aux->inimi);
		free(aux);
		
	}
	
	
}



void update_lista_3(Lista_inimi_3 *l,BITMAP* img_inimi,BITMAP* buffer,int mile){
	
	No_inimi_3 *aux=l->inicio;
	No_inimi_3 *aux2=l->inicio;
	
	while (aux != NULL){
		
		if (aux->inimi->ativo){
			
			aux->inimi->update(img_inimi,buffer,mile);
			aux2=aux;
			aux=aux->prox;
			
		}else{
			if (aux2==aux){
				l->inicio=l->inicio->prox;
				destroy_inimi_3(aux->inimi);
				free(aux);
				aux2=aux=l->inicio;
				
				
			}else{
				
				aux2->prox=aux->prox;
				destroy_inimi_3(aux->inimi);
				free(aux);
				aux=aux2->prox;
				
			}
			
			
			
		}
		
		
		
	}
	
	
}



Lista_inimi_4 *create_lista_4(){//cria a lista
	
	Lista_inimi_4* l= (Lista_inimi_4*) malloc(sizeof(Lista_inimi_4));
	
	l->inicio=NULL;
	
	return l;
	
	
}


void destroy_inimi_4 (Enemy_4 *i){//recebe o objeto
	
	free(i);
	
	
}

void destroy_lista_4(Lista_inimi_4 *l){
	
	No_inimi_4 *aux;
	
	while (l->inicio != NULL){
		
		aux= l->inicio;
		l->inicio =l->inicio->prox;
		destroy_inimi_4(aux->inimi);
		free(aux);
		
	}
	
	
}



void update_lista_4(Lista_inimi_4 *l,BITMAP* img_inimi,BITMAP* buffer,int mile){
	
	No_inimi_4 *aux=l->inicio;
	No_inimi_4 *aux2=l->inicio;
	
	while (aux != NULL){
		
		if (aux->inimi->ativo){
			
			aux->inimi->update(img_inimi,buffer,mile);
			aux2=aux;
			aux=aux->prox;
			
		}else{
			if (aux2==aux){
				l->inicio=l->inicio->prox;
				destroy_inimi_4(aux->inimi);
				free(aux);
				aux2=aux=l->inicio;
				
				
			}else{
				
				aux2->prox=aux->prox;
				destroy_inimi_4(aux->inimi);
				free(aux);
				aux=aux2->prox;
				
			}
			
			
			
		}
		
		
		
	}
	
	
}




Lista_inimi_5 *create_lista_5(){//cria a lista
	
	Lista_inimi_5* l= (Lista_inimi_5*) malloc(sizeof(Lista_inimi_5));
	
	l->inicio=NULL;
	
	return l;
	
	
}


void destroy_inimi_5 (Enemy_5 *i){//recebe o objeto
	
	free(i);
	
	
}

void destroy_lista_5(Lista_inimi_5 *l){
	
	No_inimi_5 *aux;
	
	while (l->inicio != NULL){
		
		aux= l->inicio;
		l->inicio =l->inicio->prox;
		destroy_inimi_5(aux->inimi);
		free(aux);
		
	}
	
	
}



void update_lista_5(Lista_inimi_5 *l,BITMAP* img_inimi,BITMAP* buffer,int mile){
	
	No_inimi_5 *aux=l->inicio;
	No_inimi_5 *aux2=l->inicio;
	
	while (aux != NULL){
		
		if (aux->inimi->ativo){
			
			aux->inimi->update(img_inimi,buffer,mile);
			aux2=aux;
			aux=aux->prox;
			
		}else{
			if (aux2==aux){
				l->inicio=l->inicio->prox;
				destroy_inimi_5(aux->inimi);
				free(aux);
				aux2=aux=l->inicio;
				
				
			}else{
				
				aux2->prox=aux->prox;
				destroy_inimi_5(aux->inimi);
				free(aux);
				aux=aux2->prox;
				
			}
			
			
			
		}
		
		
		
	}
	
	
}