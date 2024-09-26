// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroResorte.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

void AMuroResorte::BeginPlay()
{
	Super::BeginPlay();
}

AMuroResorte::AMuroResorte()
{
	meshMuroResorte = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroResorte"));
	meshMuroResorte->SetSimulatePhysics(false);
	meshMuroResorte->SetupAttachment(RootComponent);
	RootComponent = meshMuroResorte;
	RootComponent->SetMobility(EComponentMobility::Movable);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroResorteAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MuroResorteAsset.Succeeded())
	{
		meshMuroResorte->SetStaticMesh(MuroResorteAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'"));
	if (MaterialAsset.Succeeded())
	{
		meshMuroResorte->SetStaticMesh(MuroResorteAsset.Object);
	}

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
	}
	SetActorScale3D(FVector(2.0f, 0.25f, 2.0f));

}

void AMuroResorte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMuroResorte::AplicarEfecto()
{
	GetWorldTimerManager().SetTimer(TimerHandle_DesactivarResorte, this, &AMuroResorte::DesactivarResorte, 3.0f, false);
	PrimaryActorTick.bCanEverTick = true;
}

void AMuroResorte::DesactivarResorte()
{
	//ParticleSystem->Deactivate();
	//meshMuroResorte->SetVisibility(false);
	PrimaryActorTick.bCanEverTick = false;
}