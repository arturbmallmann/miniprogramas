map ,v :e $HOME/.vimrc<CR>
nmap <F12> :<C-u>source ~/.vimrc <BAR> echo "Vimrc recarregado!"<CR>
set nu
set showmode
set ts=4
syntax on
set ai
"set mouse=a
map <F2> <esc>:!clear&make<cr>
map <F3> <esc>:!clear&make test<cr>
map <F4> <esc>:!clear&make clean<cr>
map <F11> <esc>:set ai!<cr>
map <F9> <esc>:write<cr>
map <F10> <esc>:quit<cr>
"escopos automáticos
"imap { {}<left>
"imap [ []<left>
"imap ( ()<left>
