// C++ code
//display 7 segmentos
#define A 8
#define B 7
#define C 11
#define D 12
#define E 13
#define F 9
#define G 10

#define verde 4
#define rojo 3

#define boton1 6
#define boton2 5
#define btnStop A0

int contador = 0;
bool estadoAnterior1 = HIGH;
bool estadoAnterior2 = HIGH;
bool estadoAnteriorStop = HIGH;
int segmentos[7] = {B,A,F,G,C,D,E};
bool stoped = false;

int n0[7] = {1, 1, 1, 0, 1, 1, 1};
int n1[7] = {1, 0, 0, 0, 1, 0, 0};
int n2[7] = {1, 1, 0, 1, 0, 1, 1};
int n3[7] = {1, 1, 0, 1, 1, 1, 0};
int n4[7] = {1, 0, 1, 1, 1, 0, 0};
int n5[7] = {0, 1, 1, 1, 1, 1, 0};
int n6[7] = {0, 1, 1, 1, 1, 1, 1};
int n7[7] = {1, 1, 1, 0, 1, 0, 0};
int n8[7] = {1, 1, 1, 1, 1, 1, 1};
int n9[7] = {1, 1, 1, 1, 1, 1, 0};
  
void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  manejadorMontaCargas();
  
}

void encenderNumero(int numero[]){
  for (int i=0;i<7;i++){
    digitalWrite(segmentos[i],numero[i]);
  }
}
void manejadorDisplay(int contador){
		
  switch(contador){
    case 0:encenderNumero(n0);break;
  	case 1:encenderNumero(n1);break;
    case 2:encenderNumero(n2);break;
    case 3:encenderNumero(n3);break;
    case 4:encenderNumero(n4);break;
    case 5:encenderNumero(n5);break;
    case 6:encenderNumero(n6);break;
    case 7:encenderNumero(n7);break;
    case 8:encenderNumero(n8);break;
    case 9:encenderNumero(n9);break;
  }
  
}
void manejadorMontaCargas(){
  
  int estadoStop = digitalRead(A0);
  if(estadoStop == LOW && estadoAnteriorStop == HIGH){
  	stoped = !stoped;
    servicioEnPausa(stoped);
  
  }
  estadoAnteriorStop = estadoStop;
  
  if(stoped == true){
    manejadorDisplay(contador);
  }else{
  	manejadorDisplay(contador);
   
    int estadoPulsador1 = digitalRead(boton1);
    if (estadoPulsador1 == LOW && estadoAnterior1 == HIGH){
      decrementarContador();
      movimiento();
     
    }
    estadoAnterior1 = estadoPulsador1;
    int estadoPulsador2 = digitalRead(boton2);
    if (estadoPulsador2 == LOW && estadoAnterior2 == HIGH){
      incrementarContador();
      movimiento();
      
    }
    estadoAnterior2 = estadoPulsador2;
  }
}

void incrementarContador() {
  contador++;
  if(contador > 9){
  	contador = 0;
  }
  Serial.println("PISO ACTUAL:");
  Serial.println(contador);
  
}

void decrementarContador() {
  contador--;
  if(contador < 0){
  	contador = 9;
  }
  Serial.println("PISO ACTUAL:");
  Serial.println(contador);
 
}
void movimiento(){
  	
  	Serial.println("en Movimiento");
	digitalWrite(verde,HIGH);
  	delay(3000);
  	digitalWrite(verde,LOW);
}
void servicioEnPausa(int estadoAnterior){
  manejadorDisplay(contador-1);
  	digitalWrite(rojo,estadoAnterior);
  if(estadoAnterior == true){
  	Serial.println("en PAUSA");
    Serial.println("PISO:");
    Serial.println(contador);
  }else{
  	Serial.println("REANUDADO");
  }
}
