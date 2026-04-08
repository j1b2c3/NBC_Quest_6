#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "GameFramework/Actor.h"
#include "PlatformObs001.generated.h"

UCLASS()
class QUEST6_API APlatformObs001 : public AObstacle
{
	GENERATED_BODY()

public:
	APlatformObs001();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform")
	float ActiveTime = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform")
	float Mintime = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform")
	float Maxtime = 3.0f;

	void TogglePlatform();

	FTimerHandle PlatformTimerHandle;
	bool bIsActive = true;
};
