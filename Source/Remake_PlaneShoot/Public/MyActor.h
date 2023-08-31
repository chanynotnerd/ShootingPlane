// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class REMAKE_PLANESHOOT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UBoxComponent* Box;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UStaticMeshComponent* Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UProjectileMovementComponent* Movement;

	// Delegate ���� UFUNCTION Ű���� �ʼ�
	UFUNCTION()
	void ProcessBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION(BlueprintImplementableEvent)
	void CallCPPToBP();

	UFUNCTION(BlueprintNativeEvent)	// CPP���� BP ȣ��, �ݴ�� bp���� cppȣ���� BlueprintCallable
	void CallCPPToBPButCPP();	// �갡 ȣ��Ǹ�
	void CallCPPToBPButCPP_Implementation();	// �갡 �۵��ϹǷ� �긦 �����ؾ� ��.
};
