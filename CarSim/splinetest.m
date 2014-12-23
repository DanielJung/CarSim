clc, clear, close all;
h0=0.5;
d0=2;
[X0,Y0]=meshgrid(-d0:h0:d0,-d0:h0:d0);

f0=@(x,y)( sin(x).*sin(y) );
Z0=f0(X0,Y0);

%Liste mit Vorgabepunkten
x0=X0(:);
y0=Y0(:);
z0=Z0(:);

%g0=@(x,y,s)(exp(-(x.^2+y.^2)./(2.*s)));
%g=@(x,y)(g0(x,y,1));
%h1=1;
%d1=5;
%[x1,y1]=meshgrid(-d:h1:d,-d:h1:d);
%x1=x1(:)';
%y1=y1(:)';
%f=@(x,y)[g(x-x1,y-y1)];

%Ansatzfunktionen, Liste einfach erweitern (Rest geht automatisch)
f=@(x,y)[x.^2, y.^2, x.*y, x, y, 1];


m=length(f(0,0));
n=length(x0);

A=zeros(n,m);
b=zeros(n,1);
for i=1:n
    A(i,:)=f(x0(i),y0(i));
    b(i)=z0(i);
end

k=A\b;

h=0.2;
d=3;
[x,y]=meshgrid(-d:h:d,-d:h:d);

z=zeros(size(x));

for i=1:numel(x)
    z(i)=f(x(i),y(i))*k;
end

figure;
surf(x,y,z);
hold on
mesh(X0,Y0,Z0);
axis equal

k
max(abs((A*k-b)))
