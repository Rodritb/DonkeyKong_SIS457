// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "MuroResorte.generated.h"

class UParticleSystemComponent;
class UStaticMeshComponent;
/**
 * 
 */
UCLASS()
class DONKEYKONG_SIS457_API AMuroResorte : public AObstaculo
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	UParticleSystemComponent* ParticleSystem;
	UStaticMeshComponent* meshMuroResorte;

public:
	AMuroResorte();

public:
	virtual void Tick(float DeltaTime) override;
	virtual void AplicarEfecto() override;
private:
	FTimerHandle TimerHandle_DesactivarResorte;

	void DesactivarResorte();
	
};
