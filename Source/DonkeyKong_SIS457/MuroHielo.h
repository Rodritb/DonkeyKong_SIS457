// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "MuroHielo.generated.h"

class UParticleSystemComponent;
class UStaticMeshComponent;
/**
 * 
 */
UCLASS()
class DONKEYKONG_SIS457_API AMuroHielo : public AObstaculo
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	UParticleSystemComponent* ParticleSystem;
	UStaticMeshComponent* meshMuroHielo;


public:
	AMuroHielo();

public:
	virtual void Tick(float DeltaTime) override;
	virtual void AplicarEfecto() override;
private:
	FTimerHandle TimerHandle_Congelacion;

	void Descongelar();

};
