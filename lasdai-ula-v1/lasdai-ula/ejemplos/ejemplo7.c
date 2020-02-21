#include "../biblioteca/pr1-ula.h"

void frase(Entero, Entero);
void expresar(Entero, Entero, Entero);

#define tam 6

int main(){
  
  int id = conectarRobot(ROBOT);

    Entero a, b, c;
    Entero i = 1;
    Entero puntaje = 0;
    Caracter cadA[20]; 
    Caracter cadB[20];

    do{

      a = generarAleatorio(7,3);
      b = generarAleatorio(1,10);
      c = a * b;

      int2string(a,cadA);
      int2string(b,cadB);

      hablarRobot(id, cadA);
      hablarRobot(id, " por ");
      hablarRobot(id, cadB);

      /*cambiar respuesta por voz*/
      Entero opcion = leerEntero();
      esperar(1);
      
      /*frase motivacional cada dos preguntas*/
      if(i % 2 == 0 && i != tam){
        if(opcion == c)
          frase(id, 1);
        else
          frase(id, 0);
      }

      if(opcion == c)
        puntaje += 50;

      esperar(1);

    }while(i++ < tam);
    

    /*Puntaje total*/
    if(puntaje == 300){
      expresar(id, 5, 2);
      hablarRobot(id, "¡Excelente!, eres un genio con las tablas de multiplicar");
      expresar(id, 2, 0);
    }
    else if(puntaje >= 150 && puntaje < 300){
      expresar(id, 2, 0);
      hablarRobot(id, "Muy bien, pero sigue practicando para que puedas mejorar");
    }
    else{
      expresar(id, 1, 1);     
      expresar(id, 5, 3);         
      hablarRobot(id, "Sigue practicando para que puedas mejorar, ¡tu puedes!");
      enviarRobot(id, expresarNormal); 
    }

  desconectarRobot(id);
}


void frase(Entero id, Entero respuesta){
  
  /*cambiar aleatorio por respuesta teleoperada*/
  Entero aleatorio = generarAleatorio(0,4);

  /* 0 y 1 respuesta rápida 2 y 3 respuesta lenta */
  if(respuesta == 1){
    expresar(id, 2, 0);

    if(aleatorio == 0)
      hablarRobot(id, "¡Excelente!");
    else if(aleatorio == 1)
      hablarRobot(id, "Eres un genio");
    else if(aleatorio == 2)
      hablarRobot(id, "Lo estás haciendo bien");
    else
      hablarRobot(id, "Muy bien, sigue esforzándote");
  }
  else{
    expresar(id, 2, 1);

    if(aleatorio == 0)
      hablarRobot(id, "piensa un poco más");
    else if(aleatorio == 1)
      hablarRobot(id, "piensa antes de responder");
    else if(aleatorio == 2)
      hablarRobot(id, "No te preocupes, estaba difícil");
    else
      hablarRobot(id, "Vamos, responde bien la próxima");
  }
  esperar(1);
}

void expresar(Entero id, Entero n, Entero i){
  
  if(i == 0)
    enviarRobot(id, expresarFeliz); 
  else if(i == 1)
    enviarRobot(id, expresarTriste); 
  else if(i == 2)
    reproducirAudioInterno("ganador"); 
  else
    reproducirAudioInterno("perdedor"); 

  esperar(n);     
}