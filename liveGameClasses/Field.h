#pragma once
#include "Cell.h"
#include "windows.h"

using namespace System;
using namespace System::Drawing;

enum NbrType { // тип открестности
	Moore, Neumann, Mvon
};

ref class Field
{
	array<Cell^,2>^ cells;
	array<Cell^,2>^ cellsBuff;

	int nbrColumn, nbrLine;
	NbrType epsType;
	int width, height;
	int dBetwCell;

	int dx, dy; // смещения поля от краев
public:

	Field()
	{

	}

	void init(int nbrColumn_, int nbrLine_, int width_, NbrType epsType_)
	{
		nbrColumn = nbrColumn_;
		nbrLine = nbrLine_;
		width = height = width_;

		Cell::size = width/nbrColumn;
		dBetwCell = Cell::size/4;

		cells = gcnew array<Cell^,2>(nbrColumn, nbrLine);
		for(int i=0; i<nbrColumn; i++)
			for(int j=0; j<nbrLine; j++)
				cells[i,j] = gcnew Cell();

		cellsBuff = gcnew array<Cell^,2>(nbrColumn, nbrLine);
		for(int i=0; i<nbrColumn; i++)
			for(int j=0; j<nbrLine; j++)
				cellsBuff[i,j] = gcnew Cell();

		epsType = epsType_;

		dx = 5;
		dy = 30;
	}

	Field(int nbrColumn_, int nbrLine_, int width_)
	{
		init(nbrColumn_, nbrLine_, width_, Moore);
	}

	void changeEpsType(NbrType epsType_)
	{
		epsType = epsType_;
	}

	void nextStep()
	{
		int NbrInEps;

		for(int i=0; i<nbrColumn; i++)
			for(int j=0; j<nbrLine; j++)
			{
				NbrInEps = 0;
				switch(epsType) {
				case Moore:
					// считаем количество клеток в окрестности
					for(int s = (i==0 ? 0 : -1); s < (i==nbrColumn-1 ? 1 : 2); s++)
						for(int p = (j==0 ? 0 : -1); p < (j==nbrLine-1 ? 1 : 2); p++)
						{
							if(s==0 && p==0)
								continue;
							if(cells[i+s,j+p]->val)
								NbrInEps++;
						}
						// действуем в соответствии с правилами
						if(cells[i,j]->val)
						{
							if( NbrInEps<2 || NbrInEps > 3)
								cellsBuff[i,j]->val = 0;
							else
								cellsBuff[i,j]->val = 1;
						} else {
							if( NbrInEps == 3 )
								cellsBuff[i,j]->val = 1;
							else
								cellsBuff[i,j]->val = 0;
						}
						break;
				case Neumann:
						if(cells[max(0,i-1),j]->val)
							NbrInEps++;
						if(cells[min(i+1,nbrColumn-1),j]->val)
							NbrInEps++;
						if(cells[i,max(0,j-1)]->val)
							NbrInEps++;
						if(cells[i,min(j+1,nbrLine-1)]->val)
							NbrInEps++;
						// действуем в соответствии с правилами
						if(cells[i,j]->val)
						{
							if( NbrInEps<1 || NbrInEps > 3)
								cellsBuff[i,j]->val = 0;
							else
								cellsBuff[i,j]->val = 1;
						} else {
							if( NbrInEps == 2 )
								cellsBuff[i,j]->val = 1;
							else
								cellsBuff[i,j]->val = 0;
						}
						break;
				case Mvon:
					// считаем количество клеток в окрестности
					for(int s = (i>1 ? -2 : 0); s < (i>=nbrColumn-2 ? 1 : 3); s++)
						for(int p = (j>1 ? -2 : 0); p < (j>=nbrLine-2 ? 1 : 3); p++)
						{
							if(s==0 && p==0)
								continue;
							if(cells[i+s,j+p]->val)
								NbrInEps++;
						}
						// действуем в соответствии с правилами
						if(cells[i,j]->val)
						{
							if( NbrInEps<2 || NbrInEps > 3)
								cellsBuff[i,j]->val = 0;
							else
								cellsBuff[i,j]->val = 1;
						} else {
							if( NbrInEps == 3 )
								cellsBuff[i,j]->val = 1;
							else
								cellsBuff[i,j]->val = 0;
						}
						break;
				}

			}
			for(int i=0; i<nbrColumn; i++)
				for(int j=0; j<nbrLine; j++)
					cells[i,j]->val = cellsBuff[i,j]->val;
	}

	void drawCells(BufferedGraphics^ buff)
	{
		buff->Graphics->Clear(Color::WhiteSmoke);
		for(int i=0; i<nbrColumn; i++)
			for(int j=0; j<nbrLine; j++)
				cells[i,j]->draw(buff, i,j, dBetwCell, dx, dy);		
	}

	void mouseClick(int x, int y)
	{
		int i = (x-dx)/(Cell::size+dBetwCell);
		int j = (y-dy)/(Cell::size+dBetwCell);
		if(i >= 0 && i < nbrColumn && 
			j >= 0 && j < nbrLine)
		{
			bool a = cells[ i , j ]->val;
			cells[ i , j ]->val = !a;
		}
	}

	void random()
	{
		for(int i=0; i<nbrColumn; i++)
			for(int j=0; j<nbrLine; j++)
				cells[i,j]->val = rand()%2;
	}

	void clean()
	{
		for(int i=0; i<nbrColumn; i++)
			for(int j=0; j<nbrLine; j++)
				cells[i,j]->val = false;	
	}
};

