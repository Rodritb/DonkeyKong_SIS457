// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonkeyKong_SIS457GameMode.h"
#include "DonkeyKong_SIS457Character.h"
#include "UObject/ConstructorHelpers.h"
#include "ObstaculoMuro.h"
#include "Capsula.h"
#include "ComponentePlataforma.h"
#include "Barril.h"
#include "Esfera.h"
#include "MuroLadrillo.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"


ADonkeyKong_SIS457GameMode::ADonkeyKong_SIS457GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
}
void ADonkeyKong_SIS457GameMode::BeginPlay()
{
    Super::BeginPlay();

    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("Creando plataforma"));
    // Spawn an instance of the AMyFirstActor class at the
    //default location.
    FTransform SpawnLocation;
    SpawnLocation.SetLocation(FVector(1160.0f, -210.0f, 140.0f));
    SpawnLocation.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
    obstaculo01 = GetWorld()->SpawnActor<AObstaculoMuro>(AObstaculoMuro::StaticClass(), SpawnLocation);
	muroLadrillo01 = GetWorld()->SpawnActor<AMuroLadrillo>(AMuroLadrillo::StaticClass(), SpawnLocation);
	//obstaculo01->SetActorLocation(FVector(1160.0f, -210.0f, 140.0f));
    /*if (player01 != nullptr)
    {
        player01->SetObstaculo(obstaculo01);
    }*/

    FVector posicionInicial = FVector(1160.0f, -1100.0f, 400.f);
    FRotator rotacionInicial = FRotator(0.0f, 0.0f, 10.0f);
    FTransform SpawnLocationCP;
    float anchoComponentePlataforma = 300.0f;
    float incrementoAltoComponentePlataforma = -50.0f;
    float incrementoAltoEntrePisos = 1000.0f;
    float incrementoInicioPiso = 100.0f;

    for (int npp = 0; npp < 5; npp++) {
        rotacionInicial.Roll = rotacionInicial.Roll * -1;
        incrementoInicioPiso = incrementoInicioPiso * -1;
        incrementoAltoComponentePlataforma = incrementoAltoComponentePlataforma * -1;
        SpawnLocationCP.SetRotation(FQuat(rotacionInicial));

        for (int ncp = 0; ncp < 15; ncp++) {

            SpawnLocationCP.SetLocation(FVector(posicionInicial.X, posicionInicial.Y + anchoComponentePlataforma * ncp, posicionInicial.Z));
            AComponentePlataforma* plataforma = GetWorld()->SpawnActor<AComponentePlataforma>(AComponentePlataforma::StaticClass(), SpawnLocationCP);
            plataforma->TiempoBajar = 2.0f; // Tiempo en segundos para bajar la plataforma
            plataforma->TiempoSubir = 2.0f; // Tiempo en segundos para subir la plataforma
            plataforma->LimiteSuperior = posicionInicial.Z; // Altura máxima de la plataforma
            plataforma->LimiteInferior = posicionInicial.Z - incrementoAltoComponentePlataforma * 3; // Altura mínima de la plataforma
            ComponentesPlataforma.Add(plataforma);

            if (ncp < 14) {
                posicionInicial.Z = posicionInicial.Z + incrementoAltoComponentePlataforma;

            }
            // Establecer la dirección del movimiento según las flechas rojas

            if (ncp == 1) {
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, 0.0f, 0.0f); // Segunda plataforma hacia arriba

            }
            else if (ncp == 2) {
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, 0.0f, -1.0f); // Tercera plataforma hacia abajo


            }
            else if (ncp == 3) {
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, 0.0f, 1.0f); // Cuarta plataforma hacia arriba

            }
            else if (ncp == 4) {

                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, 0.0f, 0.0f); // Cuarta plataforma sin movimiento
            }
            else if (ncp == 5) {
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, 1.0f, 0.0f); // Cuarta plataforma hacia la derecha

            }
            else if (ncp == 6) {
				ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, 0.0f, 0.0f); // Penúltima plataforma hacia la izquierda
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->SetActorHiddenInGame(true);
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->SetActorEnableCollision(false);
            }
            else if (ncp == 7) {
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, -1.0f, 0.0f); // Última plataforma hacia abajo
            }
            else if (ncp == 8) {
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, 0.0f, 0.0f); // Cuarta plataforma sin movimiento
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->SetActorHiddenInGame(true);
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->SetActorEnableCollision(false);
            }
            else if (ncp == 9) {
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, 0.0f, 0.0f); // Cuarta plataforma sin movimiento
            }
            else if (ncp == 10) {
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, 0.0f, 0.0f); // Penúltima plataforma hacia arrib
                //El código seleccionado oculta un actor en el juego y desactiva su colisión. Específicamente, se refiere a la línea de código:
                /*SetActorHiddenInGame(true): Esta línea oculta el actor en el juego. Esto significa que la plataforma no será visible para los jugadores mientras el juego esté en ejecución.
                SetActorEnableCollision(false): Esta línea desactiva la colisión del actor. Esto significa que la plataforma no interactuará 
            físicamente con otros actores en el juego, como el jugador o cualquier otro objeto que pueda colisionar con ella.*/
               // ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->SetActorHiddenInGame(true);
                //ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->SetActorEnableCollision(false);
            }
            else if (ncp == 11) {
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, 0.0f, 0.0f); // Última plataforma hacia abajo
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->SetActorHiddenInGame(true);
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->SetActorEnableCollision(false);
            }
            else if (ncp == 12) {
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, 1.0f, 0.0f); // Cuarta plataforma sin movimiento
            }
            else if (ncp == 13) {
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, 0.0f, 0.0f); // Cuarta plataforma sin movimiento
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->SetActorHiddenInGame(true);
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->SetActorEnableCollision(false);
            }
            else if (ncp == 14) {
				ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, 0.0f, 0.0f); // Cuarta plataforma sin movimiento
            }
            else {
                ComponentesPlataforma[ComponentesPlataforma.Num() - 1]->DireccionMovimiento = FVector(0.0f, 0.0f, 0.0f); // Sin movimiento por defecto

            }
        }

           /* if (ncp != 10 && ncp != 11) {
                plataforma = GetWorld()->SpawnActor<AComponentePlataforma>(AComponentePlataforma::StaticClass(), SpawnLocationCP);
                plataforma->TiempoBajar = 2.8f; // Tiempo en segundos para bajar la plataforma
                plataforma->TiempoSubir = 2.0f; // Tiempo en segundos para subir la plataforma
                plataforma->TiempoDerecha = 4.0f;
                plataforma->TiempoIzquierda = 5.0f;
                plataforma->LimiteSuperior = posicionInicial.Z; // Altura máxima de la plataforma
                plataforma->LimiteInferior = posicionInicial.Z - incrementoAltoComponentePlataforma * 3; // Altura mínima de la plataforma
                ComponentesPlataforma.Add(plataforma);
            }*/
        

       //ComponentesPlataforma.Add(ComponentesPiso);
        posicionInicial.Z = posicionInicial.Z + incrementoAltoEntrePisos;
        posicionInicial.Y = posicionInicial.Y + incrementoInicioPiso;
    }

    GetWorld()->GetTimerManager().SetTimer(SpawnBarrilTimerHandle, this, &ADonkeyKong_SIS457GameMode::SpawnBarril, 3.0f, true);

    //Crear una esfera en la parte superior del primer piso que baje rebotando hasta llegar al suelo

    for (int nes = 0; nes < 5; nes++) {
        FTransform SpawnLocationEsfera;
        SpawnLocationEsfera.SetLocation(FVector(1300.0f, -200.0f, 1060.0f));
        SpawnLocationEsfera.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
        esferasMap.Add(nes, GetWorld()->SpawnActor<AEsfera>(AEsfera::StaticClass(), SpawnLocationEsfera));
    }

}
	
	
void ADonkeyKong_SIS457GameMode::SpawnBarril()
{
	//if (barriles.Num() >= numeroMaximoBarriles) {
	if (contadorBarriles < numeroMaximoBarriles) {
		//Spawn de un objeto barril en la escena sobre la primera plataforma
		FTransform SpawnLocationBarril;
		SpawnLocationBarril.SetLocation(FVector(1160.0f, 900.0f, 860.0f));
		SpawnLocationBarril.SetRotation(FQuat(FRotator(90.0f, 0.0f, 0.0f)));
		//ABarril* barril01 = GetWorld()->SpawnActor<ABarril>(ABarril::StaticClass(), SpawnLocationBarril);
		barriles.Add(GetWorld()->SpawnActor<ABarril>(ABarril::StaticClass(), SpawnLocationBarril));
		contadorBarriles++;

		if (contadorBarriles >= numeroMaximoBarriles) {
			GetWorld()->GetTimerManager().ClearTimer(SpawnBarrilTimerHandle);
		}
	}
	
}

