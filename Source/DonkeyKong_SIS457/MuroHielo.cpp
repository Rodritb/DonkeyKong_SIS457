#include "MuroHielo.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

void AMuroHielo::BeginPlay()
{
    Super::BeginPlay();
}

AMuroHielo::AMuroHielo()
{
    meshMuroHielo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroLadrillo"));
    meshMuroHielo->SetSimulatePhysics(false);
    meshMuroHielo->SetupAttachment(RootComponent);
    RootComponent = meshMuroHielo;
    RootComponent->SetMobility(EComponentMobility::Movable);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroLadrilloAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
    if (MuroLadrilloAsset.Succeeded())
    {
        meshMuroHielo->SetStaticMesh(MuroLadrilloAsset.Object);
    }

    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'"));
    if (MaterialAsset.Succeeded())
    {
        meshMuroHielo->SetStaticMesh(MuroLadrilloAsset.Object);
    }

    ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
    ParticleSystem->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Steam_Lit.P_Steam_Lit'"));
    if (ParticleSystemAsset.Succeeded())
    {
        ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
    }
    SetActorScale3D(FVector(2.0f, 0.25f, 2.0f));

}

void AMuroHielo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMuroHielo::AplicarEfecto()
{
	GetWorldTimerManager().SetTimer(TimerHandle_Congelacion, this, &AMuroHielo::Descongelar, 3.0f, false);
	PrimaryActorTick.bCanEverTick = true;
}

void AMuroHielo::Descongelar()
{
	//ParticleSystem->Deactivate();
	//meshMuroHielo->SetVisibility(false);
	PrimaryActorTick.bCanEverTick = false;
}

