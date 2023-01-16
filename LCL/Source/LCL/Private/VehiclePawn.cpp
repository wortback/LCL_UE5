// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiclePawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "ChaosVehicleWheel.h"


AVehiclePawn::AVehiclePawn()
{
	// Setting TickGroup to PostPhysics to work with the latest physics data
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PostPhysics;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	StaticMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	StaticMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	
	StaticMesh->BodyInstance.bSimulatePhysics = true;

	StaticMesh->PrimaryComponentTick.TickGroup = PrimaryActorTick.TickGroup;

	SetRootComponent(StaticMesh);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	SpringArm->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SpringArm->SetRelativeLocation(FVector::ZeroVector);
	SpringArm->SetRelativeRotation(FRotator::ZeroRotator);
	SpringArm->PrimaryComponentTick.TickGroup = PrimaryActorTick.TickGroup;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));

	FollowCamera->AttachToComponent(SpringArm, FAttachmentTransformRules::KeepRelativeTransform, USpringArmComponent::SocketName);
	FollowCamera->SetRelativeLocation(FVector::ZeroVector);
	FollowCamera->SetRelativeRotation(FRotator::ZeroRotator);
	FollowCamera->bUsePawnControlRotation = false;
	FollowCamera->PrimaryComponentTick.TickGroup = PrimaryActorTick.TickGroup;

	



	
}

