if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <silent> <C-Tab> =UltiSnips#ListSnippets()
inoremap <F10>  :w  :!g++-11 -fsanitize=address -std=c++20 -Wall -Wextra -Wshadow -DLOCAL -O2 -o "%<" "%" && "./%<" < inp
inoremap <F9>  :w  :!g++-11 -fsanitize=address -std=c++20 -Wall -Wextra -Wshadow -DLOCAL -O2 -o %< % && ./%< 
inoremap <F8>  :w  :!g++-11 -fsanitize=address -std=c++20 -DLOCAL -O2 -o "%<" "%" && "./%<" < inp
inoremap <F3>  :w  :make 
inoremap <F1> 
snoremap <silent>  "_c
xnoremap <silent> 	 :call UltiSnips#SaveLastVisualSelection()gvs
snoremap <silent> 	 :call UltiSnips#ExpandSnippetOrJump()
nnoremap 	 %
onoremap 	 %
snoremap  "_c
noremap  s :source ~/.vimrc 
noremap  / 0i//
noremap  a ggVG
noremap  i 	
noremap  o 
noremap  q :q
noremap  n :vs 
noremap  u i_r
noremap  j <NL>
noremap  r 
noremap  e :e .
noremap  b ^
xmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(expand((exists("g:netrw_gx")? g:netrw_gx : '<cfile>')),netrw#CheckIfRemote())
snoremap <C-R> "_c
snoremap <silent> <C-H> "_c
snoremap <silent> <Del> "_c
snoremap <silent> <BS> "_c
snoremap <silent> <C-Tab> :call UltiSnips#ListSnippets()
noremap <F10>  :w  :!g++-11 -fsanitize=address -std=c++20 -Wall -Wextra -Wshadow -DLOCAL -O2 -o %< % && ./%< < inp
noremap <F9>  :w  :!g++-11 -fsanitize=address -std=c++20 -Wall -Wextra -Wshadow -DLOCAL -O2 -o %< % && ./%< 	
noremap <F8>  :w  :!g++-11 -fsanitize=address -std=c++20 -DLOCAL -O2 -o %< % && ./%< < inp
noremap <F7>  :w !python3 
noremap <F3>  :w  :make 
vnoremap <F1> :tabprev 
nnoremap <F1> :tabprev 
onoremap <F1> :tabprev 
inoremap <silent> 	 =UltiSnips#ExpandSnippetOrJump()
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set autoread
set background=dark
set backspace=indent,eol,start
set cindent
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set history=1000
set hlsearch
set ignorecase
set incsearch
set iskeyword=@,48-57,_,192-255,:
set nomodeline
set ruler
set runtimepath=~/.vim,~/.vim/plugged/vimtex,~/.vim/plugged/ultisnips,~/.vim/plugged/vim-snippets,/var/lib/vim/addons,/etc/vim,/usr/share/vim/vimfiles,/usr/share/vim/vim81,/usr/share/vim/vimfiles/after,/etc/vim/after,/var/lib/vim/addons/after,~/.vim/plugged/vimtex/after,~/.vim/plugged/ultisnips/after,~/.vim/after
set shiftwidth=4
set smarttab
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set noswapfile
set tabstop=4
set visualbell
set window=29
" vim: set ft=vim :
