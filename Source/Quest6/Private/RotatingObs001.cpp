#include "RotatingObs001.h"

ARotatingObs001::ARotatingObs001()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh->SetupAttachment(Root);
	Mesh->SetStaticMesh(
		LoadObject<UStaticMesh>(
			nullptr, TEXT("/Game/Platformer_8_Underworld/Meshes/SM_obstacle_4_001.SM_obstacle_4_001")));
}

void ARotatingObs001::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RotationAxis * RotationSpeed * DeltaTime);
}
