# Visual Studio property pages setup
1. Open Property Manager  
2. Add a new property sheet  
3. Double click to open the property pages settings  

To keep under solution->  
Output Directory:   
$(SolutionDir)bin\$(Platform)\$(Configuration)\  

Intermediate Directory:  
$(SolutionDir)bin\intermediates\$(Platform)\$(Configuration)\  

To keep under project->  
Under Common Properties:  
Output Directory:   
$(SolutionDir)$(ProjectName)bin\$(Platform)\$(Configuration)\  

Intermediate Directory:  
$(SolutionDir)$(ProjectName)bin\intermediates\$(Platform)\$(Configuration)\  

OpenCV settings example:  
Under C/C++:  
General:  
Additional Include DIrectories: C:\opencv\build\include  

Linker:  
General: Additional Library Directories: C:\opencv\build\x64\vc15\lib  

Input: Additional Dependencies: opencv_world401d.lib;opencv_world401.lib;%(AdditionalDependencies)  




