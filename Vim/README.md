# UPDATE
Some of the issues learned here are addressed in the following projects:

- [vim-ue4](https://github.com/drichardson/vim-ue4)
- [vim-cpp](https://github.com/drichardson/vim-cpp)
- [ue4cli](https://github.com/adamrehn/ue4cli)
- [ctags-ue4cli](https://github.com/drichardson/ctags-ue4cli/)


# WORK IN PROGRESS: Vim Workflow
Demonstrates how to use Vim effectively in a C++ UE4 project, including:

- Using Vim quickfix for build errors
- Searching Game and UE4 source code
- Builging a ctags database to improve code navigation
- Code completion

This guide is written for developers working on Windows 10, but much of it
applies to other environments as well.

# Navigating Source Code

Navigating source code includes:

- Browsing directories
- Opening by filename or pattern
- Searching file contents
- Jumping to tags

## Browsing Directories

Documentation: [netrw](https://vimhelp.org/pi_netrw.txt.html)

```vim
:e source/code/directory
```

## Opening Files

Documentation: [edit-a-file](https://vimhelp.org/editing.txt.html#edit-a-file)

### By Filename

```
:e source/code/directory/file.cpp
```

## By Pattern

Documentation: [file-searching](https://vimhelp.org/editing.txt.html#file-searching)

To recursively search for files matching a pattern from the current directory:

```
:e **/f*.cpp
```

If there are more than one result, the first one will be used. To pick an option from a list instead using the [`wildmenu`](https://vimhelp.org/options.txt.html#%27wildmenu%27):

```
:e **/f*.cpp<TAB>
```

## Search File Contents

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
These examples show you how Vim code searching by default.

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

### ripgrep - Faster Code Search

[Code Search Shootout](https://github.com/drichardson/CodeSearchShootout) tests
recursive code searches with some popular grep alternatives. I use
[`ripgrep`](https://github.com/BurntSushi/ripgrep) because it is the fastest
code search tool that is actively maintained.

To configure vim to use `ripgrep`, install `ripgrep`, make sure `rg` is in your
`PATH`, and then add this to *.vimrc*:

``` vim
if executable('rg')
    set grepprg=rg\ -Hn\ --trim
endif
```

### Code Search Key Mappings
Here are some suggested key mappings [key mappings](https://vimhelp.org/map.txt.html).

``` vim
noremap <F3> :cprev<CR>
noremap <F4> :cnext<CR>
noremap <S-F4> :grep <cword><CR>
noremap <F5> :colder<CR>
noremap <F6> :cnewer<CR>
```

These mappings work with all quickfix windows (search results and build results).

- F3: previous entry
- F4: next entry
- Shift+F4: grep for word under cursor
- F5: go to a previous error/search result list
- F6: go to a newer error/search result list

## Jumping to Tags

Documentation:

- [tagsrch](https://vimhelp.org/tagsrch.txt.html)
- [Universal Ctags Docs](https://docs.ctags.io/en/latest/)

1. Install [Universal Ctags](https://github.com/universal-ctags/ctags).
2. Build a tags database with:

    cd my/source/directory
    ctags -R .

3. Lookup tags
    - :tag SomeSymbol - goto tag
    - CTRL-] - goto tag under cursor
    - :tselect SomeSymbol - open list of matching tags


# Building

Documentation: [quickfix](https://vimhelp.org/quickfix.txt.html)

# Code Completion

Documentation:

- [`'completefunc'`](https://vimhelp.org/options.txt.html#%27completefunc%27)
- [`'omnifunc'`](https://vimhelp.org/options.txt.html#%27omnifunc%27)


#### Tag Base Code Completion

You can also use the tags database for code completion with
[i_CTRL-X_CTRL-]](https://vimhelp.org/insert.txt.html#compl-tag).

### Snippets

Snippet plugins like [UltiSnips](https://github.com/SirVer/ultisnips) can be
used to automate repetative typing tasks, like calling UE_LOG or adding a
UPROPERTY. There are several UE4 snippet libraries, including one I maintain
called [vim-ue4](https://github.com/drichardson/vim-ue4).

To use vim-ue4, install Ultisnips and vim-ue4 like any vim package, and then in insert mode, press tab after the snippet name to expand the snippet.

I also add the following to my *.vimrc* so that UltiSnips uses Tab and Shift+Tab to move throught the snippet fields:

``` vim
let g:UltiSnipsExpandTrigger = "<Tab>"
let g:UltiSnipsJumpBackwardTrigger = "<S-Tab>"
let g:UltiSnipsJumpForwardTrigger = "<Tab>"
let g:UltiSnipsListSnippets = "<Leader>l"
```


