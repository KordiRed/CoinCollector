// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"

// For GetAllActorsOfClass()
#include "Kismet/GameplayStatics.h"
// For Num()
#include "Containers/Array.h"
//For widgets calling
#include "Blueprint/UserWidget.h"

#include "Ball.generated.h"

UCLASS()
class COINCOLLECTOR_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	//Counter numbers of coins (Called from Coin.cpp)
	int CoinCounter;
	//Called from Coin.cpp when we colect last coin
	void FinishLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// WidgetClass variable declaration
	TSubclassOf<class UUserWidget> LevelCompleteWidgetClass;
	//An array of coins
	TArray<AActor*> CoinActorsArray;
};
