package main

import (
	"time"
)

type TaskStatus int
const (
	TASK_STATUS_UNSPECIFIED TaskStatus = 0
	TASK_STATUS_IN_PROGRESS TaskStatus = 1
	TASK_STATUS_COMPLETED   TaskStatus = 2
	TASK_STATUS_CREATED     TaskStatus = 3
)

type TaskInterface interface {
	GetTaskStatus() TaskStatus
	GetId() string
	GetTitle() string
	GetDeadline() *time.Time
	GetCreatedAt() *time.Time
	GetCompletedat() *time.Time
}

var _ TaskInterface = &Task{}

type Task struct {
	taskId   string
	title    string
	deadline *time.Time
	createdAt *time.Time
	completedAt *time.Time
	taskStatus TaskStatus
}

func (t *Task) GetTaskStatus() TaskStatus{
	if t == nil {
		return TASK_STATUS_UNSPECIFIED
	}

	return t.taskStatus
}

func (t *Task) GetId() string {
	if(t == nil){
		return ""
	}

	return t.taskId 
}

func (t *Task) GetTitle() string {
	if(t == nil){
		return ""
	}

	return t.title 
}

func (t *Task) GetDeadline() *time.Time {
	if(t == nil){
		return nil
	}

	return t.deadline 
}

func (t *Task) GetCreatedAt() *time.Time {
	if(t == nil){
		return nil
	}

	return t.createdAt
}

func (t *Task) GetCompletedat() *time.Time {
	if(t == nil){
		return nil
	}

	return t.completedAt 
}

//TODO: implement setters at the end