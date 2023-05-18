# 1º Parcial-SPD "Montacargas hospital"

Se diseño un programa donde se opera un montacargas, donde el usuario puede avanzar, retroceder y pausar el
montacargas en un piso especifico...

Alumno Lucas Figueroa 1J

![image](https://github.com/lucas22-f/1Parcial-SPD/assets/71677198/1f2cd3a5-ae96-4245-b78c-507c40312516)

## Componentes utilizados

- Arduino Uno
- Display de 7 segmentos
- Resistencias
- Botones
- LED verde y LED rojo

## Configuración de pines

El código utiliza los siguientes pines para conectar los componentes:

```
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
```
## Configuración inicial

En la función `setup`, se configuran los pines como entrada o salida según sea necesario.

## Bucle principal

En el bucle principal `loop`, se llama a la función `manejadorMontaCargas` para controlar el funcionamiento del programa.


El programa contiene las siguientes funciones principales:

- `encenderNumero`: Esta función enciende los segmentos correspondientes para mostrar un número en el display.
- `manejadorDisplay`: Esta función selecciona qué número se debe mostrar en el display según el valor del contador.
- `manejadorMontaCargas`: Esta función es el bucle principal del programa. Controla la lógica de incrementar o decrementar el contador según los botones presionados, así como también la lógica de pausar el servicio.
- `incrementarContador`: Esta función incrementa el valor del contador y muestra el nuevo valor en el display.
- `decrementarContador`: Esta función decrementa el valor del contador y muestra el nuevo valor en el display.
- `movimiento`: Esta función activa un LED verde para indicar movimiento durante un periodo de tiempo.
- `servicioEnPausa`: Esta función muestra en el display el estado de pausa del servicio y enciende o apaga un LED rojo según sea necesario.


## Función `manejadorMontaCargas()`
```cpp
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
```

Esta función es responsable de controlar el funcionamiento principal del programa. Controla el estado del botón de parada (`btnStop`), los botones de incremento (`boton2`) y decremento (`boton1`), y decide si el servicio debe estar en pausa o no.

### Comportamiento

1. Lee el estado actual del botón de parada utilizando `digitalRead(A0)` y lo guarda en la variable `estadoStop`.
2. Compara el estado actual del botón de parada con el estado anterior almacenado en la variable `estadoAnteriorStop`.
3. Si el estado actual es `LOW` (presionado) y el estado anterior es `HIGH` (no presionado), se invierte el valor de la variable `stoped` y se llama a la función `servicioEnPausa(stoped)` para reflejar el nuevo estado.
4. Actualiza el estado anterior del botón de parada con el valor actual.
5. Si el servicio está en pausa (`stoped == true`), llama a la función `manejadorDisplay(contador)` para mostrar el número actual en el display.
6. Si el servicio no está en pausa (`stoped == false`), también llama a la función `manejadorDisplay(contador)` para mostrar el número actual en el display y continúa con las siguientes acciones:
   - Evaluamos el boton de decremento para saber si se pulsó, en caso de que se haya pulsado se ejecuta el `decremento` se produce el `informe` y el `movimiento` del montacargas
   - Evaluamos el boton de incremento para saber si se pulsó, en caso de que se haya pulsado se ejecuta el `incremento` se produce el `informe` y el `movimiento` del montacargas

### Uso

Se llama a la funcion : `manejadorMontaCargas()`en el bucle principal para manejar todo el programa.
