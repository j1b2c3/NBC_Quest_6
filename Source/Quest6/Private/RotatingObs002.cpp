#include "RotatingObs002.h"

ARotatingObs002::ARotatingObs002()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh->SetupAttachment(Root);
	Mesh->SetStaticMesh(
		LoadObject<UStaticMesh>(
			nullptr, TEXT("/Game/Platformer_8_Underworld/Meshes/SM_obstacle_1_002.SM_obstacle_1_002")));
}

void ARotatingObs002::BeginPlay()
{
	Super::BeginPlay();
}

void ARotatingObs002::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	float DeltaMovement = FMath::Sin(RotationSpeed * RunningTime);

	FRotator NewRotation = RotationAxis * DeltaMovement * Range;
	Mesh->SetRelativeRotation(NewRotation);
}
