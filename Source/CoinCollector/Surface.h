// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"

#include "Surface.generated.h"

UCLASS()
class COINCOLLECTOR_API ASurface : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASurface();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* Camera;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Axis functions
	void RotateUpDown(float AxisValue);
	void RotateLeftRight(float AxisValue);

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
