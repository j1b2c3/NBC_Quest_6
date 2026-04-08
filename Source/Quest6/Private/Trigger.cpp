#include "Trigger.h"
#include "Target.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"

ATrigger::ATrigger()
{
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
	RootComponent = TriggerVolume;

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint"));
	SpawnPoint->SetupAttachment(RootComponent);

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ATrigger::OnOverlapBegin);
}

void ATrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                              bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		if (GetWorld() && TargetClass)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			FRotator SpawnRotation = FRotator::ZeroRotator;
			FVector SpawnLocation = SpawnPoint->GetComponentLocation();
			AActor* SpawnedActor = GetWorld()->SpawnActor<ATarget>(TargetClass, SpawnLocation, SpawnRotation,
			                                                       SpawnParams);

			if (SpawnedActor)
			{
				TriggerVolume->SetCollisionEnabled(ECollisionEnabled::NoCollision);
				UE_LOG(LogTemp, Warning, TEXT("Spawn Success!"));
			}
		}
	}
}
