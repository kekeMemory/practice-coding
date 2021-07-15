#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "point.h"
using namespace std;



PLIST LlCreate(){
    PLIST p = new LIST;
    p->count = 0;
    p->head = NULL;
    p->tail = NULL;
    return p;
}

void LlDestroy( PLIST list )
{
    if (list)
    {
        LlClear(list);
        delete list;
    }
    
}
void LlClear( PLIST list ){
    if(!list){
        cout << "LlClear: Parameter illegal." <<endl;
        exit(1);
    }
    while (list->head)
    {
        PNODE t = list->head;
        list->head = t->next;
        PtDestroy(t->data);
        delete t;
        list->count--;
    }
    list->tail = NULL;   
}

void LlAppend( PLIST list, PPOINT point )
{
	PNODE t = new NODE;
	if( !list || !point ){ cout << "LlAppend: Parameter illegal." << endl; exit(1); }
	t->data = point;
	t->next = NULL;
	if( !list->head )
	{
		list->head = t;
		list->tail = t;
	}
	else
	{
		list->tail->next = t;
		list->tail = t;
	}
	list->count++;
}

void LlInsert( PLIST list, PPOINT point, unsigned int pos )
{
	if( !list || !point )
	{
		cout << "LlInsert: Parameter illegal." << endl;
		exit(1);
	}
	if( pos < list->count )
	{
		PNODE t = new NODE;
		t->data = point;
		t->next = NULL;
		if( pos == 0 )
		{
			t->next = list->head;
			list->head = t;
		}
		else
		{
			unsigned int i;
			PNODE u = list->head;
			for( i = 0; i < pos - 1; ++i )
			u = u->next;
			t->next = u->next;
			u->next = t;
		}
		list->count++;
		}
		else
		LlAppend( list, point );
}

void LlDelete( PLIST list, unsigned int pos )
{
	if( !list )
	{
		cout << "LlDelete: Parameter illegal." << endl;
		exit(1);
	}
	if( list->count == 0 )
		return;
	if( pos == 0 )
	{
		PNODE t = list->head;
		list->head = t->next;
	if( !t->next )
	list->tail = NULL;
	PtDestroy( t->data );
	delete t;
	list->count--;
}

void LlTraverse( PLIST list )
{
	PNODE t = list->head;
	if( !list )
	{
	cout << "LlTraverse: Parameter illegal." << endl;
	exit(1);
	}
	while( t )
	{
		cout << PtTransformIntoString(t->data) << " -> ";
		t = t->next;
	}
	cout << "NULL\n";
}

bool LlSearch( PLIST list, PPOINT point )
{
	PNODE t = list->head;
	if( !list || !point )
	{
		cout << "LlSearch: Parameter illegal." << endl;
		exit(1);
	}
	while( t )
	{
		if( PtCompare( t->data, point ) )
		return true;
		t = t->next;
	}
	return false;
}