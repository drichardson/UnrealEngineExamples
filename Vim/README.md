# WORK IN PROGRESS: Vim Workflow
Demonstrates how to use Vim effectively in a C++ UE4 project, including:

- Using Vim quickfix for build errors
- Searching Game and UE4 source code
- Builging a ctags database to improve code navigation
- Poor man's code completion

This guide is written for developers working on Windows 10, but much of it
applies to other environments as well.

Vim's built in functionality is used as much as possible, instead of relying on plugins.

## Code Navigation: Browsing with netrw

Documentation: [netrw](https://vimhelp.org/pi_netrw.txt.htm)

```vim
:e source/code/directory
```

## Code Navigation: Open

Documentation: [edit-a-file](https://vimhelp.org/editing.txt.html#edit-a-file)

```
:e source/code/directory/file.cpp
```

## Code Navigation: Open with Pattern

Documentation: [file-searching](https://vimhelp.org/editing.txt.html#file-searching)

To recursively search for files matching a pattern from the current directory:

```
:e **/f*.cpp
```

https://vimhelp.org/options.txt.html#%27wildmenu%27


If there are more than one result, the first one will be used. To pick an option from a list instead using the [`wildmenu`](https://vimhelp.org/options.txt.html#%27wildmenu%27):

```
:e **/f*.cpp<TAB>
```

## Quickfixing Build Errors

Documentation: [quickfix](https://vimhelp.org/quickfix.txt.html)


## Code Search

Documentation: [quickfix](https://vimhelp.org/quickfix.txt.html)

Visual Studio has [Find in
Files](https://docs.microsoft.com/en-us/visualstudio/ide/find-in-files) to
search code in projects and directories.

To search source code in vim, either
[`:grep`](https://vimhelp.org/quickfix.txt.html#grep) or
[`:vimgrep`](https://vimhelp.org/quickfix.txt.html#%3Avimgrep) is used, which
opens the same [quickfix](https://vimhelp.org/quickfix.txt.html#quickfix)
window that can be used to jump through the results list. `:grep` runs the
program set in the
['grepprg'](https://vimhelp.org/options.txt.html#%27grepprg%27) option.
`:vimgrep`, is Vim's built in search tool, but is much slower since every file
searched is subject to Vim processing that happens on every file loaded into
Vim.

### Default Vim Usage
These examples show you how vim works out of the box.

#### Search in Current Directory

##### `findstr`

```vim
:grep SearchTerm *
```

##### `vimgrep`

``` vim
:vimgrep SearchTerm *
```

#### Recursive Search

##### `findstr`

``` vim
:grep /s SearchTerm *
```

##### `vimgrep`

``` vim
:vimgrep SearchTerm */**
```

### Rescursive Search

By default, the `:grep` command does not recursively search directories. For source code, this is inconvenient. To do recursive search by default, change `grepprg` like so:

With `findstr`:

``` vim
set grepprg=findstr\ /n\ /s \ /p
```


### Faster Code Search

[Code Search
Shootout](https://github.com/drichardson/CodeSearchShootout) tests recursive
code searches with some popular grep alternatives. I use [`ripgrep`](https://github.com/BurntSushi/ripgrep) because it is the fastest code search tool that is actively maintained.

To configure vim to use `ripgrep`, install `ripgrep`, make sure `rg` is in your
`PATH`, and then add this to *.vimrc*:

``` vim
if executable('rg')
    set grepprg=rg\ -Hn\ --trim
endif
``` 

### Code Search Key Mappings
You can also add [key mappings](https://vimhelp.org/map.txt.html) to reduce typing for comm

``` vim
noremap <F3> :cprev<CR>
noremap <F4> :cnext<CR>
noremap <S-F4> :grep <cword><CR>
" Shift+F4 doesn't work through ssh+windows terminal, so instead map the
" sequence ssh sees instead. I got this by typing Control+V, Shift+F4.
map 
```

## Code Completion

## Code Navigation
