// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DonkeyKong_SIS457GameMode.generated.h"

class AObstaculoMuro;
class AComponentePlataforma;
class ADonkeyKong_SIS457Character;
class ABarril;
class AEsfera;
class AMuroLadrillo;

UCLASS(minimalapi)
class ADonkeyKong_SIS457GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADonkeyKong_SIS457GameMode();

	AObstaculoMuro* obstaculo01;
	ADonkeyKong_SIS457Character* player01;
	AMuroLadrillo* muroLadrillo01;
	TArray<AComponentePlataforma*> ComponentesPlataforma;
	//TArray<AComponentePlataforma*> ComponentesPlataforma;
	TArray<ABarril*> barriles;
	TMap<int32, AEsfera*> esferasMap;
	
	

protected:	
	virtual void BeginPlay() override;
	//TArray<int32> aComponentesPlataformaMoviles;
	

private:
	FTimerHandle SpawnBarrilTimerHandle;
	void SpawnBarril();

	int32 contadorBarriles;
	const int32 numeroMaximoBarriles = 3;

};



