// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "VehiclePawn.generated.h"

/**
 * 
 */
UCLASS()
class LCL_API AVehiclePawn : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:
	AVehiclePawn();

	UPROPERTY(EditAnywhere, Category = Vehicle)
		class UStaticMeshComponent* StaticMesh = nullptr;
	UPROPERTY(EditAnywhere, Category = Camera)
		class USpringArmComponent* SpringArm = nullptr;
	UPROPERTY(EditAnywhere, Category = Camera)
		class UCameraComponent* FollowCamera = nullptr;

	
};
