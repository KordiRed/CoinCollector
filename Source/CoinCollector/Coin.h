#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Coin.generated.h"

UCLASS()
class COINCOLLECTOR_API ACoin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoin();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* CoinMesh;

	//RotationRate for AddActorLocalRotation 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationRate;

	// Declare overlap begin function
	UFUNCTION()
	void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
