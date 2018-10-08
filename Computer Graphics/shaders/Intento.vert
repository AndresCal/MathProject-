#version 330

out vec3 InterpolatedColor;

uniform float time;

vec2 createCircle(float vertexId){
  float ux = floor(vertexId / 6.0) + mod(vertexId, 2.0);
  float vy = mod(floor(vertexId / 2.0) + floor (vertexId /3.0), 2.0);
  
  float angle = ux /20.0 * radians(180.0) * 2.0;
  float radius = vy + 1.0;
  
  float x = radius * cos(angle);
  float y = radius * sin(angle);
  
  vec2 xy = vec2(x,y);
  return xy;  
}

void main() 
{ 
  
  float circleId = floor(vertexId/(20.0*6.0));
  float numCircles = floor(vertexCount / (20.0*6.0));
  
  float down = floor(sqrt(numCircles));
  float across = floor(numCircles / down);
  
  float x = mod(circleId, across);
  float y = floor(circleId / across);
  
  float u = x / (across - 1.0);
  float v = y / (across - 1.0);
  
  float xOffset = cos(time + y * 0.2) * 0.1;
  float yOffset = cos(time + x * 0.3) * 0.2;
  
  float ux = u * 2.0 - 1.0 + xOffset;
  float vy = v * 2.0 - 1.0 + yOffset;
  
  vec2 xy = createCircle(vertexId) * 0.1 + vec2(ux,vy)*0.7;
  
  gl_Position= vec4(xy , 0.0, 1.0);
  InterpolatedColor = vec3(0.0, 0.0, 0.0);
}