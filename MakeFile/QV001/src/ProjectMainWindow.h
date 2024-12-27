 /**********************************************************************

  �ļ���: ProjectMainWindow.h
  Copyright (c) ��Bin����. All rights reserved.
  ������Ϣ�����: http://blog.csdn.net/webzhuce

  **********************************************************************/

#ifndef Project_MainWindow_H
#define Project_MainWindow_H

#include <QMainWindow>
#include "ui_CTViewer.h"
#include <vtkSmartPointer.h>



class vtkImageViewer2;
class vtkRenderer;
class vtkEventQtSlotConnect;
class vtkObject;
class vtkCommand;
class vtkResliceImageViewer;
class vtkImagePlaneWidget;
class vtkDistanceWidget;
class vtkResliceImageViewerMeasurements;
class vtkImageCast;
class vtkImageMagnify;
class vtkImageConstantPad;
class vtkStripper;
class vtkDICOMImageReader;
class vtkVolumeRayCastMapper;
class vtkVolumeProperty;
class vtkContourFilter;

class ProjectMainWindow : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT

public:
	ProjectMainWindow();
	~ProjectMainWindow();

private slots:
	//��Ӧ��ͼ���ļ��Ĳۺ���
	void onOpenSlotDCM();//��dcmͼ��
	void onOpenSlotJPG();//��jpgͼ��
	void onOpenSlotBMP();//��bmpͼ��
	void onOpenlistphoto();//��ȡ����ͼ��

	void threeD_module();//��ά��ģ������ƣ�
	void area_module();//�����

	void Zoom();//ͼ����С
	void Amplify();//ͼ��Ŵ�

	void gray();//ͼ��Ҷ�

	void volumeph();//���
	//void areaph();//���

	void On_pushButton();//���°�ť
	void Slider();//�������л���
	void Slider_grey();//�����ҶȻ���

	void lable();//��ע

	//��Ӧ����ƶ�����Ϣ��ʵʱ������ĵ�ǰλ��
	void updateCoords(vtkObject* obj);

	void three_get();//��ȡ��ά��������
	void three_gray();//��������Ҷȱ仯

	void save();//�����ĵ�

protected:
    vtkSmartPointer< vtkResliceImageViewer > riw[3];
    vtkSmartPointer< vtkImagePlaneWidget > planeWidget[3];
    vtkSmartPointer< vtkDistanceWidget > DistanceWidget[3];
    vtkSmartPointer< vtkResliceImageViewerMeasurements > ResliceMeasurements;
	vtkSmartPointer< vtkRenderer > ren;
	vtkSmartPointer<vtkImageCast> readerImageCast;
	vtkSmartPointer<vtkImageConstantPad> rdImageCast;
	vtkSmartPointer<vtkImageViewer2> imageViewerButton;
	vtkSmartPointer<vtkDICOMImageReader>dicomImagereader;
	vtkSmartPointer<vtkVolumeRayCastMapper>volumeMapper;
	vtkSmartPointer<vtkVolumeProperty>volumeProperty;
	
private:
	vtkSmartPointer< vtkImageViewer2 >           m_pImageViewer;
	vtkSmartPointer< vtkRenderer >                   m_pRenderder;

	vtkEventQtSlotConnect* m_Connections;
	vtkStripper* skinStripper;
};

#endif
