// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "MuroLadrillo.generated.h"

class UParticleSystemComponent;
class UStaticMeshComponent;
/**
 * 
 */
UCLASS()
class DONKEYKONG_SIS457_API AMuroLadrillo : public AObstaculo
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UParticleSystemComponent* ParticleSystem;
	UStaticMeshComponent* meshMuroLadrillo;

public:
	AMuroLadrillo();

public: 
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
