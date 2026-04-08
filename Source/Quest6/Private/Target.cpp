#include "Target.h"

ATarget::ATarget()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
	Mesh->SetStaticMesh(
		LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Platformer_8_Underworld/Meshes/SM_crown_001.SM_crown_001")));
}

void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.f, 100.f * DeltaTime, 0.f));

	RunningTime += DeltaTime;
	float DeltaMovement = FMath::Sin(MovementSpeed * RunningTime);
	AddActorLocalOffset(DeltaMovement * FVector(0.f, 0.f, 1.f));
}
