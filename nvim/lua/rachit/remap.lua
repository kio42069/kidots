vim.g.mapleader = " "

vim.keymap.set("n", "<leader>rw", vim.cmd.Ex)

vim.keymap.set("n", "<leader>mk", vim.cmd.make)
vim.keymap.set("n", "Y", ":%w !xclip -i -sel c<CR>")
vim.keymap.set("v", "Y", '"+y"')
