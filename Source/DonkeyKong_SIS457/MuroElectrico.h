// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "MuroElectrico.generated.h"

class UParticleSystemComponent;
class UStaticMeshComponent;
/**
 * 
 */
UCLASS()
class DONKEYKONG_SIS457_API AMuroElectrico : public AObstaculo
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	UParticleSystemComponent* ParticleSystem;
	UStaticMeshComponent* meshMuroElectrico;

public:

	AMuroElectrico();

public:
	virtual void Tick(float DeltaTime) override;

	
};
