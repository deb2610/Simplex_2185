#include "AppClass.h"
void Application::InitVariables(void)
{
	/*m_pCameraMngr->SetPositionTargetAndUpward(
		vector3(0,0,0),
	);*/
	//init the mesh
	m_pMesh = new MyMesh();
	m_pMesh2 = new MyMesh();
	//m_pMesh->GenerateCube(1.0f, C_WHITE);
	m_pMesh->GenerateSphere(1.0f, 5, C_WHITE);
	m_pMesh2->GenerateTorus(3.0f,1.0f, 10,10, C_BLUE);
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

	matrix4 m4Model = IDENTITY_M4;
	//m4Model = glm::translate(vector3(1.0));
	
	static DWORD startTime = GetTickCount();
	DWORD currentTime = GetTickCount();
	DWORD deltaTime = currentTime - startTime;
	//m_pMeshMngr->PrintLine("%i", static const <int>time);
	//std::cout << "Time: " << deltaTime/1000.0f << std::endl;

	uint uClock = m_pSystem->GenClock();
	float fDeltaTime = m_pSystem->GetDeltaTime(uClock);
	std::cout << "Time: " << fDeltaTime/1000.0f << std::endl;
	//method 1 dumb shit
	/*vector4 v4 = m4Model[3];
	v4.x = 1.0f;
	m4Model[3] = v4;*/

	//method 2 - dirrect
	//m4Model[3][0] = 1.0f;

	//method 3 - glm vector (nice)
	//m4Model = glm::translate(vector3(1.0f, 1.0f, 0.0f));
	static float f1transX = 0.00f;
	matrix4 m4trans = glm::translate(vector3(f1transX, 1.0f, 0.0f));
	f1transX += 0.01f;
	//scaleing
	//method 1 - loop dirrect
	/*for (size_t i = 0; i < 3; i++)
	{
		m4Model[i][i] = 20.0f;

	}*/
	//glm scaling
	//m4Model = glm::scale(IDENTITY_M4, vector3(5.0f));
	matrix4 m4scale = glm::scale(IDENTITY_M4, vector3(1.0f));

	//m4Model = m4trans * m4scale;
	m4Model = m4scale * m4trans;

	m_pMesh->Render(m4Projection, m4View, m4Model);
	m_pMesh2->Render(m4Projection, m4View, m4Model);
	
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
	SafeDelete(m_pMesh);

	//release GUI
	ShutdownGUI();
}