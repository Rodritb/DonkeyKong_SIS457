// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroLadrillo.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"


AMuroLadrillo::AMuroLadrillo()
{
	meshMuroLadrillo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroLadrillo"));
	meshMuroLadrillo->SetSimulatePhysics(false);
	meshMuroLadrillo->SetupAttachment(RootComponent);
	RootComponent = meshMuroLadrillo;
	RootComponent->SetMobility(EComponentMobility::Movable);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroLadrilloAsset(TEXT("StaticMesh'/Game/Modelos3D/stone_wall_wall_stone.stone_wall_wall_stone'"));
	if (MuroLadrilloAsset.Succeeded())
	{
		meshMuroLadrillo->SetStaticMesh(MuroLadrilloAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));
	if (MaterialAsset.Succeeded())
	{
		meshMuroLadrillo->SetMaterial(0, MaterialAsset.Object);
	}

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
	}

	SetActorScale3D(FVector(2.0f, 0.25f, 2.0f));
}

void AMuroLadrillo::BeginPlay()
{
	Super::BeginPlay();
}

void AMuroLadrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

