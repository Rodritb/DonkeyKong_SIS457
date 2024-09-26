// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroElectrico.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

void AMuroElectrico::BeginPlay()
{
	Super::BeginPlay();
}

AMuroElectrico::AMuroElectrico()
{
	meshMuroElectrico = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroElectrico"));
	meshMuroElectrico->SetSimulatePhysics(false);
	meshMuroElectrico->SetupAttachment(RootComponent);
	RootComponent = meshMuroElectrico;
	RootComponent->SetMobility(EComponentMobility::Movable);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroLadrilloAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MuroLadrilloAsset.Succeeded())
	{
		meshMuroElectrico->SetStaticMesh(MuroLadrilloAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));
	if (MaterialAsset.Succeeded())
	{
		meshMuroElectrico->SetMaterial(0, MaterialAsset.Object);
	}

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Sparks.P_Sparks'"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
	}
	SetActorScale3D(FVector(2.0f, 0.25f, 2.0f));
}

void AMuroElectrico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
