#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

UCLASS()
class QUEST6_API ATarget : public AActor
{
	GENERATED_BODY()

public:
	ATarget();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Target")
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	UStaticMeshComponent* Mesh;

protected:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	float RunningTime = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	float MovementSpeed = 1.0f;
};
