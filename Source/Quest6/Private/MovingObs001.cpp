#include "MovingObs001.h"

AMovingObs001::AMovingObs001()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh->SetupAttachment(Root);
	Mesh->SetStaticMesh(
		LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Platformer_8_Underworld/Meshes/SM_pillar_004.SM_pillar_004")));
}

void AMovingObs001::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

void AMovingObs001::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	float DeltaMovement = FMath::Sin(MovementSpeed * RunningTime);

	FVector NewLocation = StartLocation + DeltaMovement * MoveDirection * Range;
	SetActorLocation(NewLocation);
}
