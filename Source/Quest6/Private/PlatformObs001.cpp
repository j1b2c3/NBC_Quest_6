#include "PlatformObs001.h"

APlatformObs001::APlatformObs001()
{
	Mesh->SetupAttachment(Root);
	Mesh->SetStaticMesh(

		LoadObject<UStaticMesh>(
			nullptr, TEXT("/Game/Platformer_8_Underworld/Meshes/SM_obstacle_7_001.SM_obstacle_7_001")));
}


void APlatformObs001::BeginPlay()
{
	Super::BeginPlay();

	float InitalWait = FMath::RandRange(Mintime, Maxtime);
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &APlatformObs001::TogglePlatform, InitalWait, false);
}

void APlatformObs001::TogglePlatform()
{
	bIsActive = !bIsActive;

	if (Mesh)
	{
		Mesh->SetVisibility(bIsActive);

		ECollisionEnabled::Type NewCollision = bIsActive
			                                       ? ECollisionEnabled::QueryAndPhysics
			                                       : ECollisionEnabled::NoCollision;
		Mesh->SetCollisionEnabled(NewCollision);
	}

	float NextWaitTime;
	if (bIsActive)
	{
		NextWaitTime = ActiveTime;
	}
	else
	{
		NextWaitTime = FMath::RandRange(Mintime, Maxtime);
	}

	GetWorld()->GetTimerManager().SetTimer(PlatformTimerHandle, this, &APlatformObs001::TogglePlatform, NextWaitTime,
	                                       false);
}
