#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
using namespace std;


void framebuffer_size_callback(GLFWwindow* window ,int width, int height);
void processinput(GLFWwindow *window);

int main()
{
  cout<<"hell";
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

# ifdef __linux__ 
  glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
#endif
  
// create a window of custom size
  GLFWwindow* window =glfwCreateWindow(800,600,"OPENGL",NULL,NULL);
  if (window==NULL){
    cout<<"failed to create a window "<<endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
   
  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
      {
        cout<<"failed to initialise the glad"<<endl;
        glfwTerminate();
        return -1;
      }
  
  glViewport(0,0,800,600);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f,  0.5f, 0.0f
  };
  
  unsigned int VBO;
  glGenBuffers(1,&VBO);

  glBindBuffer(GL_ARRAY_BUFFER,VBO);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices, GL_STATIC_DRAW);

// main loop which iterartes till said no

  while(!glfwWindowShouldClose(window))
  {
    //for checking the press key
    processinput(window);
    //changing the color
    glClearColor(0.2f,0.3f,0.3f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }


  glfwTerminate();
  return 0;


}
// every time the window is resized its size has to be registered in the glViewport so that it resizes the window
void framebuffer_size_callback(GLFWwindow *window, int width,int height)
{
  glViewport(0,0,width,height);
}
// if you want to resize to have the escape key to close your window
void processinput(GLFWwindow *window)
{
  if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window,true);
  }
}
