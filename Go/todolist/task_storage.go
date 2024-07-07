package main

type TaskStorage interface {
	AddTask(task TaskInterface)
	GetAllTasks() ([]TaskInterface)
}

var _ TaskStorage = &ListTaskStorage{}

type ListTaskStorage struct{
	TaskList []TaskInterface
}

func NewListTaskStorage() *ListTaskStorage{
	return &ListTaskStorage{
		TaskList: []TaskInterface{},
	}
}

func (l *ListTaskStorage) GetAllTasks() []TaskInterface{
	return l.TaskList
}

func (l *ListTaskStorage) AddTask(task TaskInterface) {
	l.TaskList = append(l.TaskList, task)
}