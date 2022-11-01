#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"

//For widgets calling
#include "Blueprint/UserWidget.h"

#include "DeathTriggerBox.generated.h"

UCLASS()
class COINCOLLECTOR_API ADeathTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

public:
	ADeathTriggerBox();

	// Declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// WidgetClass variable declaration
	TSubclassOf<class UUserWidget> GameOverWidgetClass;
};