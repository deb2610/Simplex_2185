#include "AppClass.h"
void Application::InitVariables(void)
{
	/*m_pCameraMngr->SetPositionTargetAndUpward(
		vector3(0,0,0),
	);*/
	//init the mesh
	//m_pMesh2 = new MyMesh();
	//m_pMesh->GenerateCube(1.0f, C_WHITE);
	//m_pMesh->GenerateSphere(1.0f, 5, C_WHITE);
	
	m_pMesh = new MyMesh();
	m_pMesh->GenerateCube(1.0f, C_BLUE);
	for (size_t i = 0; i < 47; i++)
	{
		meshList.push_back(m_pMesh);
		defTransformsList.push_back(IDENTITY_M4);
	}
	//row 4 - top
	defTransformsList[0] = glm::translate(vector3(-3.0f, 4.0f, 0.0f));
	defTransformsList[1] = glm::translate(vector3(3.0f, 4.0f, 0.0f));
	//row 3 
	defTransformsList[2] = glm::translate(vector3(-2.0f, 3.0f, 0.0f));
	defTransformsList[3] = glm::translate(vector3(2.0f, 3.0f, 0.0f));
	//row 2
	defTransformsList[4] = glm::translate(vector3(-3.0f, 2.0f, 0.0f));
	defTransformsList[5] = glm::translate(vector3(-2.0f, 2.0f, 0.0f));
	defTransformsList[6] = glm::translate(vector3(-1.0f, 2.0f, 0.0f));
	defTransformsList[7] = glm::translate(vector3(0.0f, 2.0f, 0.0f));
	defTransformsList[8] = glm::translate(vector3(1.0f, 2.0f, 0.0f));
	defTransformsList[9] = glm::translate(vector3(2.0f, 2.0f, 0.0f));
	defTransformsList[10] = glm::translate(vector3(3.0f, 2.0f, 0.0f));
	//row 1
	defTransformsList[11] = glm::translate(vector3(-4.0f, 1.0f, 0.0f));
	defTransformsList[12] = glm::translate(vector3(-3.0f, 1.0f, 0.0f));
	defTransformsList[13] = glm::translate(vector3(-1.0f, 1.0f, 0.0f));
	defTransformsList[14] = glm::translate(vector3(0.0f, 1.0f, 0.0f));
	defTransformsList[15] = glm::translate(vector3(1.0f, 1.0f, 0.0f));
	defTransformsList[16] = glm::translate(vector3(3.0f, 1.0f, 0.0f));
	defTransformsList[17] = glm::translate(vector3(4.0f, 1.0f, 0.0f));
	//row 0
	defTransformsList[18] = glm::translate(vector3(-5.0f, 0.0f, 0.0f));
	defTransformsList[19] = glm::translate(vector3(-4.0f, 0.0f, 0.0f));
	defTransformsList[20] = glm::translate(vector3(-3.0f, 0.0f, 0.0f));
	defTransformsList[21] = glm::translate(vector3(-2.0f, 0.0f, 0.0f));
	defTransformsList[22] = glm::translate(vector3(-1.0f, 0.0f, 0.0f));
	defTransformsList[23] = glm::translate(vector3(0.0f, 0.0f, 0.0f));
	defTransformsList[24] = glm::translate(vector3(1.0f, 0.0f, 0.0f));
	defTransformsList[25] = glm::translate(vector3(2.0f, 0.0f, 0.0f));
	defTransformsList[26] = glm::translate(vector3(3.0f, 0.0f, 0.0f));
	defTransformsList[27] = glm::translate(vector3(4.0f, 0.0f, 0.0f));
	defTransformsList[28] = glm::translate(vector3(5.0f, 0.0f, 0.0f));
	//row -1
	defTransformsList[29] = glm::translate(vector3(-5.0f, -1.0f, 0.0f));
	defTransformsList[30] = glm::translate(vector3(-3.0f, -1.0f, 0.0f));
	defTransformsList[31] = glm::translate(vector3(-3.0f, -1.0f, 0.0f));
	defTransformsList[32] = glm::translate(vector3(-2.0f, -1.0f, 0.0f));
	defTransformsList[33] = glm::translate(vector3(-1.0f, -1.0f, 0.0f));
	defTransformsList[34] = glm::translate(vector3(0.0f, -1.0f, 0.0f));
	defTransformsList[35] = glm::translate(vector3(1.0f, -1.0f, 0.0f));
	defTransformsList[36] = glm::translate(vector3(2.0f, -1.0f, 0.0f));
	defTransformsList[37] = glm::translate(vector3(3.0f, -1.0f, 0.0f));
	defTransformsList[38] = glm::translate(vector3(5.0f, -1.0f, 0.0f));
	//row -2
	defTransformsList[39] = glm::translate(vector3(-5.0f, -2.0f, 0.0f));
	defTransformsList[40] = glm::translate(vector3(-3.0f, -2.0f, 0.0f));
	defTransformsList[41] = glm::translate(vector3(3.0f, -2.0f, 0.0f));
	defTransformsList[42] = glm::translate(vector3(5.0f, -2.0f, 0.0f));
	//row -3
	defTransformsList[43] = glm::translate(vector3(-2.0f, -3.0f, 0.0f));
	defTransformsList[44] = glm::translate(vector3(-1.0f, -3.0f, 0.0f));
	defTransformsList[45] = glm::translate(vector3(1.0f, -3.0f, 0.0f));
	defTransformsList[46] = glm::translate(vector3(2.0f, -3.0f, 0.0f));




	//m_pMesh1 = new MyMesh();
	//m_pMesh1->GenerateCube(1.0f, C_RED);
	//meshList.push_back(m_pMesh1);
	//m_pMesh2->GenerateTorus(3.0f,1.0f, 10,10, C_BLUE);
}
void Application::Update(void)
{
	

	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	
	//matrix4 m4Scale = glm::scale(IDENTITY_M4, vector3(2.0f,2.0f,2.0f));
	//static float value = 0.0f;
	//matrix4 m4Translate = glm::translate(IDENTITY_M4, vector3(value, 2.0f, 3.0f));
	//value += 0.01f;

	////matrix4 m4Model = m4Translate * m4Scale;
	//matrix4 m4Model = m4Scale * m4Translate;
	
	static DWORD startTime = GetTickCount();
	DWORD currentTime = GetTickCount();
	DWORD deltaTime = currentTime - startTime;

	uint uClock = m_pSystem->GenClock();
	float fDeltaTime = m_pSystem->GetDeltaTime(uClock);
	//std::cout << "Time: " << fDeltaTime/1000.0f << std::endl;

	//glm scaling
	//m4Model = glm::scale(IDENTITY_M4, vector3(5.0f));
	//matrix4 m4scale = glm::scale(IDENTITY_M4, vector3(1.0f));


	//flaoting plz
	static float f1transX = 0.00f;
	static float f1transY = 0.00f;
	matrix4 m4trans = glm::translate(vector3(f1transX, f1transY, 0.0f));
	for (size_t i = 0; i < 47; i++)
	{
		meshList[i]->Render(m4Projection, m4View, defTransformsList[i] * m4trans);
	}
	f1transX += 0.01f;
	f1transY += sin(f1transX*1)/20;
	
	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	m_pMeshMngr->AddGridToRenderList();
	
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	for (size_t i = 0; i < 47; i++)
	{
		SafeDelete(meshList[i]);

	}

	//release GUI
	ShutdownGUI();
}