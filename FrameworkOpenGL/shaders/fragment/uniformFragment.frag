#version 330 core

out vec4 FragColor;
uniform float ActualColor;

void main()
{
    FragColor = vec4(0.0f, ActualColor, 1.0f, 1.0f);
}
