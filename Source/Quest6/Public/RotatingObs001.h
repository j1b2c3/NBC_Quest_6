#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "GameFramework/Actor.h"
#include "RotatingObs001.generated.h"

UCLASS()
class QUEST6_API ARotatingObs001 : public AObstacle
{
	GENERATED_BODY()

public:
	ARotatingObs001();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float RotationSpeed = 210.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FRotator RotationAxis = FRotator(0.f, 1.f, 0.f);

	virtual void Tick(float DeltaTime) override;
};
