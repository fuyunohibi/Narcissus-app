g++ -o App App.cpp
./App

<h1>Narcissus App</h1>


<h5><u>IMPORTANT!</u></h5>
<p>
  Before starting any work on your local repository, run <b>git pull</b> to ensure that you are working with the latest version of the codebase.
</p>


<h4>Login Page</h4>
<ul>
  <li><b>username:</b> mesan</li>
  <li><b>password:</b> 1234</li>
</ul>


<h4>Text Styles</h4>
<p>Available methods:</p>
<ul>
  <li><b>setFontWeight</b></li>
  <li><b>setColors</b></li>
</ul>
<p>Example:</p>
<blockquote>
    setFontWeight(FontWeight::weight, setColor(Color::color, ""))
</blockquote>


<br>


<h5><u>FLASH</u></h5>
<p>
  <b>git commit</b> - saves changes locally. Git creates a new commit that contains the changes you have made since your last commit.
</p>
<p>
  <b>git push</b> - sends those changes to a remote repository. Git sends the commits you have made in your local repository to a remote repository. This updates the remote repository with your changes, allowing others to access them.
</p>
<p>
  <b>git pull</b> - updates a local repository with changes made in a remote repository. This keeps your local repository up-to-date with the latest changes made by other developers in a shared repository.
</p>


<br>



<h2>WARNING: Include Guards</h2>

<p>To prevent multiple inclusions, add include guards to the header files. In C++, you can use:</p>

<blockquote>
  <p>#ifndef MY_HEADER_FILE_H</p>
  <p>#define MY_HEADER_FILE_H</p>
  <p>// Header file code goes here</p>
  <p>#endif // MY_HEADER_FILE_H</p>
</blockquote>

<p>The `#ifndef` and `#define` statements create an include guard that prevents the header file from being included more than once in a single compilation unit.</p>


