class Pai{
	public:
	
	float pos_x,pos_y,vel_x,vel_y,ace_x,ace_y;
	int vida,ataque,linha,coluna;
	bool ativo,gravidade=true;
//	BITMAP* inimi_img,buffer;
	int** mapa;
	
	
	
	
	void update(){
		
		
		
		
		
	}
	
	private:
	
	
	
	
	
	
};


class Enemy_1:public Pai{
	public:

	
	Enemy_1(int** mapa,int linha,int coluna,int i,int j,int mile){
		this->linha=linha;
		this->coluna=coluna;
		this->mapa=mapa;
		this->pos_x=j;
		this->pos_y=i;
		this->p1_xy=0;
		this->p2_x=100;
		this->p3_y=100;
		this->p4_xy=100;
		this->esq=this->pos_x-100;
		this->dir=this->pos_x+500;
		this->muda_dir=-1;
		this->frame=328/4;
		this->frame_v=0;
		this->frame_atual=0;
		this->tempo=mile;
		this->vida=3;
		
		
		ativo=true;
		
	}
	
virtual	 void update(BITMAP* img_inimi,BITMAP* buffer,int mile){
		
		
		
		this->verificar(mile);
		this->caiu();
		this->colisao();
		this->dano(buffer);
		masked_blit(img_inimi,buffer,frame*frame_atual,frame_v,this->pos_x+x,this->pos_y+y,frame,100);
	}
	
	void colisao(){
		static int colidiu[100][100];
		static bool queda=false;
		int m_w=81,m_h=27,cal_x=0,cal_y=0;
		
		for(int i=0;i< this->linha;i++){
			for(int j=0;j< this->coluna;j++){
				
				if(mapa[i][j]==grama){
				
				
				if ((this->pos_x+this->p1_xy+x>=j*72+x+370) && (this->pos_x+this->p1_xy+x<=j*72+x+m_w+370) && ((this->pos_y+this->p3_y-22)+y>=i*20+y+2+10) && ((this->pos_y+this->p3_y-22)+y<=i*20+y+40+10)){
					//p3 lado esquerdo
					
					
						this->gravidade=false;
				
							for(int p=0;p<100;p++){
								for(int q=0;q<100;q++){
									colidiu[p][q]=-1;
									
									
								}
								
							}
					
					colidiu[i][j]=1;
								
						
				
				}else if(!queda){
					queda=true;
					
					
				}/*else if(colidiu[i][j]==1 && pular)
					colidiu[i][j]=-1;
				*/
				else if(colidiu[i][j]==1 && queda){
					gravidade=true;
				//	pular=false;
					
				}
				
			}else if(mapa[i][j]==terra_lado_1){
					
					
					if(((this->pos_x+this->p4_xy-22)+x>=j*90+x) && ((this->pos_x+this->p4_xy-22)+x<=j*90+x+10) && ((this->pos_y+this->p4_xy-22)+y>=i*21+y+2) && (this->pos_y+this->p4_xy<=i*21+y+40)){
						
						
						this->muda_dir=-1;
						frame_atual=0;
						
						
					}
					
					
				}else if(mapa[i][j]==terra_lado_2){
					
					if(((this->pos_x+this->p4_xy-22)+x>=(j*90+x+60)-190) && ((this->pos_x+this->p4_xy-22)+x<=(j*90+x+140)-190) && ((this->pos_y+this->p4_xy-22)+y>=i*21+y+2) && (this->pos_y+this->p4_xy<=i*21+y+40)){
						
						
						this->muda_dir=1;
						frame_atual=2;
						
						
					}
					
					
					
					
				}
				
			}
			
		}
		
		
	}
	
virtual void dano(BITMAP* buffer){//existe um bug onde o player é jogado e não cai
	
	//rectfill(buffer,this->pos_x+x,this->pos_y+y+50,this->pos_x+x+60,this->pos_y+y+60,makecol(0,255,0));
	
	if((hit_x>=this->pos_x+x) && (hit_x<=this->pos_x+x+60) && (hit_y>=this->pos_y+y+50) && (hit_y<=this->pos_y+y+60)){
		
		if(lado==0){
			
			this->pos_x+=400;
			this->pos_y-=200;
			this->vida--;
			
		}else if(lado==1){
			
			this->pos_x-=400;
			this->pos_y-=200;
			this->vida--;
			
		}
		
		
	}
	
	if(this->vida<=0)this->ativo=false;
	if(hit_x_bomb>=this->pos_x+x-300 && hit_x_bomb<=this->pos_x+x+300 && hit_y_bomb>=this->pos_y+y-300 && hit_y_bomb<=this->pos_y+y+300)this->vida--;
	
	
}
	
	
virtual void verificar(int mile){
	
	if((pos_player_x>(this->pos_x-200)+x) && (pos_player_x<this->pos_x+200+x) && (pos_player_y>=this->pos_y+y-100) && (pos_player_y<=this->pos_y+y+50)){
		
			this->ataca(mile);
	
	}else
			this->caminha(mile);
	
	
}
	
	
virtual void ataca(int mile){
	
	
	if((this->pos_x+x<pos_player_x-49) && (pos_player_y<=this->pos_y+y+50) && (pos_player_y>=this->pos_y+y-100)){
		
		frame_atual=2;
		this->pos_x++;
		
		
	}else if((this->pos_x+x>pos_player_x+35) && (pos_player_y<=this->pos_y+y+50) && (pos_player_y>=this->pos_y+y-100)){
		
		frame_atual=0;
		this->pos_x--;
		
		
	}
	

	
	
	if(mile - tempo >= 500){
		
		if(frame_atual==3)
			frame_atual=2;
		else if(frame_atual==2)
			frame_atual=3;
		else if(frame_atual==0)
			frame_atual=1;
		else if(frame_atual==1)
			frame_atual=0;
		
		tempo=mile;
	}
	
	
		if((this->pos_x+x<pos_player_x+35) && (this->pos_x+x>pos_player_x-49) && (pos_player_y<=this->pos_y+y+50) && (pos_player_y>=this->pos_y+y-100)){
		
				frame_v=116;
			
				if((this->pos_x+x>pos_player_x-80) && (this->pos_x+x<pos_player_x)){
					
					
					frame_atual=1;
					golpe=1;
					lado=1;
					hp-=1;
					
				}
			
			
				if ((this->pos_x+x<pos_player_x+80) && (this->pos_x+x>pos_player_x)){
					
					
					frame_atual=0;
					golpe=1;
					lado=0;
					hp-=1;
				}
			
		
	}else
			frame_v=0;
	
	
	
	
}
	
	
virtual void caminha(int mile){
	
	
	if(mile - tempo >= 500){
		
		if(frame_atual==3)
			frame_atual=2;
		else if(frame_atual==2)
			frame_atual=3;
		else if(frame_atual==0)
			frame_atual=1;
		else if(frame_atual==1)
			frame_atual=0;
		
		tempo=mile;
	}
	
	
	if(this->pos_x+x<this->esq+x){
		frame_atual=2;
		
		
			this->muda_dir=1;
		
		
	}else if(this->pos_x+x>this->dir+x){
		frame_atual=0;
		
			this->muda_dir=-1;
		
		
	}
		
	
	
	this->pos_x+=this->muda_dir;
//	this->vel_x=muda_dir;
	
}
	
void caiu(){
	
	if (this->gravidade){
		
		
		this->pos_y++;
		
	}
	
	
}
	protected:
	
	int	p1_xy=0,p2_x=100,p3_y=100,p4_xy=100;
	int esq,dir,muda_dir,frame,frame_atual,tempo,frame_v;
};



class Enemy_2:public Enemy_1{
	public:
	int frame_atual,tempo_2,tempo_3,tempo_4,cima;
	bool stp=false,stop_frame,stop_frame_2,parou_cima;
	
	Enemy_2(int** mapa,int linha,int coluna,int i, int j,int mile):Enemy_1(mapa, linha,coluna, i,  j, mile){
		
		this->pos_x=j;
		this->pos_y=i;
		this->mapa=mapa;
		this->linha=linha;
		this->coluna=coluna;
		this->tempo=mile;
		this->tempo_2=mile;
		this->tempo_3=mile;
		this->tempo_4=mile;
		this->esq=this->pos_x-100;
		this->dir=this->pos_x+100;
		this->cima=this->pos_y-600;
		this->vel_y=5.0;
		this->vel_x=5.0;
		this->frame_atual=0;
		this->frame=576/7;
		this->stop_frame=false;
		this->stop_frame_2=false;
		this->parou_cima=false;
		this->vida=8;
		
		
		
		this->ativo=true;
	}
	

	void update(BITMAP* img_inimi,BITMAP* buffer,int mile)override{
		
		
		
		this->caiu();
		this->verificar(mile);
		this->colisao();
		this->dano(buffer);
		this->time_pequeno(mile,stp);
		masked_blit(img_inimi,buffer,frame*frame_atual,230,this->pos_x+x,this->pos_y+y,60,80);
	}
	
	
	void verificar(int mile)override{
		
		
		if((pos_player_x>=this->pos_x+x-600) && (pos_player_x<=this->pos_x+x+600) && (pos_player_y>=this->pos_y+y-600) && (pos_player_y<=this->pos_y+y+600)){
			
			this->ataca(mile);
		}else
			this->caminha(mile);
		
		
	}
	
	void ataca(int mile)override{
		
			
		if(this->pos_y<this->cima+y)
			parou_cima=true;
		
		if(!parou_cima){
			

			if(pos_player_x<this->pos_x+x)
				this->frame_atual=4;
			if(pos_player_x>this->pos_x+x)
				this->frame_atual=3;
			
			this->pos_y-=this->vel_y;
			
		}
	
		
		
		if(parou_cima && gravidade){
			
			frame_atual=0;
			this->pos_y+=this->vel_y;
			
			if((this->pos_x+x+50>=pos_player_x) && (this->pos_x+x+50<=pos_player_x+p2_x) && (this->pos_y+y+50>=pos_player_y) && (this->pos_y+y+50<=pos_player_y+p4_xy-22)){
				
				pos_player_y-=300;
				
				if(this->pos_x+x>pos_player_x)
					x+=300;
				if(this->pos_x+x<pos_player_x)
					x-=300;
			}
			
		}
		
		
		
		if(!this->parou_cima){
			
			
			if(this->pos_x+x>pos_player_x)
				this->pos_x-=this->vel_x;
			if(this->pos_x+x<pos_player_x)
				this->pos_x+=this->vel_x;
		
			
			
		}
		
		if(this->parou_cima && !gravidade){
			
			
			if(mile - this->tempo_4 >=5000){
				
				this->parou_cima=false;
				
				
				this->tempo_4=mile;
			}
			
			
			
			
		}
		
	}
	
	
	void caminha(int mile)override{
	
		static int valor_ale=0;
		
		srand(time(NULL));
		valor_ale=rand() % 1000;
	
		
		if(valor_ale>=500){
			
			if(mile - tempo >= 700){

				if(frame_atual==2)
					frame_atual=1;
				else if(frame_atual==1)
					frame_atual=2;
				else if(frame_atual==3)
					frame_atual=4;
				else if(frame_atual==4)
					frame_atual=3;


				tempo=mile;
			}
			
			
		}
		
		if(valor_ale<500){
			
			if(mile - tempo >= 200){

				if(frame_atual==2)
					frame_atual=1;
				else if(frame_atual==1)
					frame_atual=2;
				else if(frame_atual==3)
					frame_atual=4;
				else if(frame_atual==4)
					frame_atual=3;


				tempo=mile;
			}
			
			
		}
	
		
		if(this->pos_x+x<this->esq+30+x && !this->stop_frame){
			
			
			this->stop_frame=true;
			this->stop_frame_2=true;
			
		}
		if(this->pos_x+x>(this->dir-30)+x && !this->stop_frame){
			
			this->stop_frame=true;
			this->stop_frame_2=true;
			
			
		}
		
		
		
		if(stop_frame){
			
			if(mile - this->tempo_3 >=5000){
				
				this->stop_frame_2=false;
				this->stop_frame=false;
				this->frame_atual=2;
				this->tempo_3=mile;
			
			}
		}
	
	if(this->pos_x+x<this->esq+x && !this->stop_frame_2)
	//	frame_atual=2;
		this->muda_dir=1;
		else if(this->stop_frame && this->pos_x+x<this->esq+x)
			frame_atual=4;
		
			
	 if(this->pos_x+x>this->dir+x && !this->stop_frame_2)
		//frame_atual=0;
			this->muda_dir=-1;
		else if(this->pos_x+x>this->dir+x && this->stop_frame)
			frame_atual=3;
		
		
		
		
	if(stp){
		
		if(mile - this->tempo_2 >=valor_ale){

			this->pos_x+=this->muda_dir;

			tempo_2=mile;
		}
		
	}
//	this->vel_x=muda_dir;
	
}
	
	void dano(BITMAP* buffer)override{
		
	//	rectfill(buffer,hit_x_bomb,hit_y_bomb,hit_x_bomb+400+20,hit_y_bomb+400+20,makecol(255,0,0));
	//	rectfill(buffer,this->pos_x+x+80,this->pos_y+y+80,this->pos_x+x+80+20,this->pos_y+y+80+20,makecol(0,222,0));
		
		if((this->pos_x+x+80>=hit_x_bomb-400) && (this->pos_x+x+80<=hit_x_bomb+400) && (this->pos_y+y+80>=hit_y_bomb-400) && (this->pos_y+y+80<=hit_y_bomb+400)){
			
			
			this->ativo=false;
			
			
		}
		
		
		if((hit_x>=this->pos_x+x) && (hit_x<=this->pos_x+x+80) && (hit_y>=this->pos_y+y) && (hit_y<=this->pos_y+y+80)){
			
			this->vida--;
			
			if(this->vida<=0)
			this->ativo=false;
			
			
		}
		
		
		
	}
	
	
	void time_pequeno(int mile,bool stop=false);
	
};

void Enemy_2::time_pequeno(int mile,bool stop){

	
	if(!stop){
		
		
		if(mile - this->tempo_2 >=3000){

			this->frame_atual=2;

			this->tempo_2=mile;
			this->stp=true;
	}
	
		
	}
	
	

	
	
	
	
}


class Enemy_3:public Enemy_1{
	
	public:
	int salto,pos_y_cu;
	bool desce_cu;
	
	
	Enemy_3(int** mapa,int linha,int coluna,int i,int j,int mile):Enemy_1(mapa,linha,coluna,i,j,mile){
		
		this->pos_x=j;
		this->pos_y=i;
		this->pos_y_cu=0;
		this->mapa=mapa;
		this->linha=linha;
		this->coluna=coluna;
		this->frame=203;
		this->frame_atual=0;
		this->desce_cu=false;
		
		
		
		this->ativo=true;
	}
	
	
	void update(BITMAP* img_inimi,BITMAP* buffer,int mile){
		
		
		
		this->escalar(buffer,img_inimi,mile);
		masked_blit(img_inimi,buffer,frame,172,this->pos_x+x,this->pos_y+y,30,30);
	}
	
	
	
void cagou(BITMAP* buffer,BITMAP* img_inimi){
	
	if((pos_player_x>=this->pos_x-20+x && pos_player_x<=this->pos_x+20+x && pos_player_y+p1_xy>=this->pos_y+y  && pos_player_y+20<=this->pos_y+500+y ) || this->desce_cu){
		
		this->pos_y_cu++;
		this->desce_cu=true;
		masked_blit(img_inimi,buffer,203,172,this->pos_x+x,this->pos_y+y+this->pos_y_cu,10,7);
		
		if(this->pos_y_cu> SCREEN_H){
			
			this->desce_cu=false;
			this->pos_y_cu=0;
			
		}
	}
	
	
}
	
	
void escalar(BITMAP* buffer,BITMAP* img_inimi,int mile){
	
	this->salto= (mile/500) % 2;
	this->pos_y-=0.07;
	this->cagou(buffer,img_inimi);
	if (salto){frame=203;}else{frame=232;}
	
	
	
	
}
	
	
	
};

class Enemy_4:public Enemy_1{
	public:
	float lim_width,lim_hidth,dir_h,dir_v,lim_v,lim_h;
	int frame_anim,corre_asa,outra_corre_asa,lado,frame_anim_v,cabelo,cabelo_h,corre_cabelo,mais_uma_corre,id;
	
	
	Enemy_4(int** mapa,int linha,int coluna,int i,int j,int mile):Enemy_1(mapa,linha,coluna,i,j,mile){
		
		this->pos_x=j;
		this->pos_y=i;
		this->lim_width=this->pos_x;
		this->lim_hidth=this->pos_y;
		this->dir_h=1;
		this->dir_v=1;
		this->lim_v=600;
		this->lim_h=600;
		this->frame_anim=28;
		this->frame=21;
		this->frame_anim_v=448;
		this->cabelo=416;
		this->cabelo_h=6;
		this->corre_cabelo=9;
		this->mais_uma_corre=0;
		this->id=mile;
		this->lado=1;
		
		
		
		
		this->ativo=true;
		
		
	}
	
	
void update(BITMAP* img_inimi,BITMAP* buffer,int mile) override{
	
	
	if(pos_player_x>=this->pos_x+x-170 && pos_player_x<=this->pos_x+x+170 && pos_player_y>=this->pos_y+y-200 && pos_player_y<=this->pos_y+y+200 && !sexy){
		
		fugir();
		
		
	}else if(!sexy){
	
	
		voar(img_inimi,buffer,mile);
		
		
		
	}
	
	atracao(img_inimi,buffer,mile);
	if(!sexy){
		
		
		anim_asa(img_inimi,buffer,mile);
		masked_blit(img_inimi,buffer,frame,347*this->lado,this->pos_x+x,this->pos_y+y,40,56);
		
		
		
	}
	
}
	
	
	
void atracao(BITMAP* img_inimi,BITMAP* buffer,int mile){
	
	if(sexy){
		
		if(alvo==-1)
			alvo=this->id;

	}
	
	if(alvo==this->id){
		
		if(this->pos_x+x>pos_player_x+p4_xy-22)
			this->pos_x-=4;
		if(this->pos_x+x<pos_player_x+p4_xy-22)
			this->pos_x+=4;
		if(this->pos_y+y>pos_player_y+22)
			this->pos_y-=4;
		if(this->pos_y+y<pos_player_y+22)
			this->pos_y+=4;
		
		
		if(this->pos_x+x>=pos_player_x && this->pos_x+x<=pos_player_x+p4_xy && this->pos_y+y>=pos_player_y && this->pos_y+y<=pos_player_y+p4_xy){
			
			
			poder(img_inimi,buffer,mile);
			
		}
		
	}
	
	
	
}
	
	
	
void poder(BITMAP* img_inimi,BITMAP* buffer,int mile){
	
	this->lado=2;
	masked_blit(img_inimi,buffer,this->cabelo_h,this->cabelo,this->pos_x+x-40,this->pos_y+y-10,10,19);
	
	
	if(mile - this->tempo >= 3000){
	
	
	
		masked_blit(img_inimi,buffer,139,350,this->pos_x+x-80,this->pos_y+y-8,70,56);
	
		if(hp<5)
			hp++;
		else{
			
			alvo=-1;
			sexy=false;
			
		}
		this->tempo=mile;
	}else
	
	masked_blit(img_inimi,buffer,67,350,this->pos_x+x-80,this->pos_y+y-8,70,56);
	
	
	
	
}
	
	
	
void fugir(){
	
	
	if(pos_player_x>this->pos_x+x){this->pos_x-=5;this->lado=1;}else if(pos_player_x<this->pos_x+x){this->pos_x+=5;this->lado=2;}
	if(pos_player_y>this->pos_y+y)this->pos_y-=5;else if(pos_player_y<this->pos_y+y)this->pos_y+=5;
	
		
	
}
	
	
	
void voar(BITMAP* img_inimi,BITMAP* buffer,int mile){
	
	
	if(this->pos_x+x <= this->lim_width+x-lim_h){
	
		this->dir_h=1;
		srand(time(NULL));
		lim_h=rand() % 500;
		
		
	}else if (this->pos_x+x >=this->lim_width+x+lim_h){
		
		this->dir_h=-1;		
		srand(time(NULL));
		lim_h=rand() % 600;
		
	}
	
	if (this->pos_y+y<=this->lim_hidth+y-lim_v){
		
		this->dir_v=1;
		srand(time(NULL));
		lim_v=rand() % 500;
	
	}else if(this->pos_y+y>=this->dir_v+y+lim_v){
		
		this->dir_v=-1;
		srand(time(NULL));
		lim_v=rand() % 600;
		
		
	}
	
	this->pos_x+=dir_h;
	this->pos_y+=dir_v;
}
	
	
void anim_asa(BITMAP* img_inimi,BITMAP* buffer,int mile){
	
	this->frame_atual= (mile/200) % 4;
	
	if(this->frame_atual==0)this->frame_atual=1;
	if(this->frame_atual==1){
		
		if(this->lado==1)this->corre_asa=7;else this->corre_asa=30;
		
		
	}
	
	 if(this->frame_atual==1) if(this->lado==1) this->outra_corre_asa=0;else this->outra_corre_asa=5;
	
	if(this->frame_atual==3){
		
		if(this->lado==1){this->corre_asa=10;this->outra_corre_asa=10;}else{ this->corre_asa=30;this->outra_corre_asa=18;}
	
	
	}
	if(this->frame_atual==0)this->corre_asa=0;
	
	masked_blit(img_inimi,buffer,frame_anim*this->frame_atual+this->outra_corre_asa,frame_anim_v,this->pos_x+x+10-this->corre_asa,this->pos_y+y,40,56);
	
	//esse é o cabelo da fadia o próximo if precisa incluir o outro lado
	masked_blit(img_inimi,buffer,this->cabelo_h,this->cabelo,this->pos_x+x+this->corre_cabelo,this->pos_y+y+this->mais_uma_corre,10,19);
	
	
	if(this->lado==2){
		
		
		this->frame_anim_v=514;
		this->cabelo=462;
		this->cabelo_h=180;
		this->corre_cabelo=5;
		this->mais_uma_corre=4;
	
	}else if(this->lado=1){
		
		frame_anim_v=448;
		this->cabelo=416;
		this->cabelo_h=6;
		this->corre_cabelo=9;
		this->mais_uma_corre=0;
	
	
	}
	
}
	
	
};


class Enemy_5: public Enemy_1{
	public:
	
	Enemy_5(int** mapa,int linha,int coluna,int i,int j,int mile):Enemy_1(mapa,linha,coluna,i,j,mile){
		
		this->pos_x=j;
		this->pos_y=i;
		this->frame=300;
		
			
		
		this->ativo=true;
		
	}
	
	void update(BITMAP* img_inimi,BITMAP* buffer,int mile) override{
		
		
		
	//	rectfill(buffer,500,500,600,600,makecol(255,0,0));
		masked_blit(img_inimi,buffer,frame,150,this->pos_x+x,this->pos_y+y,100,60);
		
	}
	
	
	
	
};





typedef struct no_inimi{
	
	Enemy_1 *inimi;
	struct no_inimi *prox;
	
	
}No_inimi;


typedef struct lista_inimi{
	
	 No_inimi* inicio;
	
	
	
}Lista_inimi;






typedef struct no_inimi_2{
	
	Enemy_2 *inimi;
	struct no_inimi_2 *prox;
	
	
}No_inimi_2;


typedef struct lista_inimi_2{
	
	 No_inimi_2* inicio;
	
	
	
}Lista_inimi_2;


typedef struct no_inimi_3{
	
	Enemy_3 *inimi;
	struct no_inimi_3 *prox;
	
	
}No_inimi_3;


typedef struct lista_inimi_3{
	
	 No_inimi_3* inicio;
	
	
	
}Lista_inimi_3;


typedef struct no_inimi_4{
	
	Enemy_4 *inimi;
	struct no_inimi_4 *prox;
	
	
}No_inimi_4;


typedef struct lista_inimi_4{
	
	 No_inimi_4* inicio;
	
	
	
}Lista_inimi_4;



typedef struct no_inimi_5{
	
	Enemy_5 *inimi;
	struct no_inimi_5 *prox;
	
	
}No_inimi_5;


typedef struct lista_inimi_5{
	
	 No_inimi_5* inicio;
	
	
	
}Lista_inimi_5;



//não consegui coloca no cabeçalho

void desenha_mapa(BITMAP* img_item,BITMAP* m,BITMAP* buffer,int **mapa,int linha,int coluna,Lista_inimi* l,Lista_inimi_2* l2=NULL,Lista_inimi_3* l3=NULL,Lista_inimi_4* l4=NULL,Lista_inimi_5* l5=NULL);