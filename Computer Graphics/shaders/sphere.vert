#version 330 core

out vec3 InterpolatedColor;

uniform float time;

void main()
{
  float angle = radians(mod(gl_VertexID * 5.0, 180.0));
  float angle2 = radians(mod(floor(gl_VertexID / (180.0 / 5.0)) * 5.0, 360.0));
  
  float x = sin(angle) * cos(angle2);
  float y = sin(angle) * sin(angle2);
  float z = cos(angle);
  
  vec3 vector = vec3(x, y, z);

  mat4 matrizZ = mat4(1.0);
  matrizZ[0][0] = cos(time);
  matrizZ[1][0] = -sin(time);
  matrizZ[0][1] = sin(time);
  matrizZ[1][1] = cos(time);
  
  mat4 matrizX = mat4(1.0);
  matrizX[1][1] = cos(time);
  matrizX[2][1] = -sin(time);
  matrizX[1][2] = sin(time);
  matrizX[2][2] = cos(time);
  
  gl_Position = matrizZ * matrizX * vec4(vector, 1.0);
  gl_PointSize = 2.0;
  InterpolatedColor = vec3(1.0, 0.0, 0.0);
}