/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:52:23 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/12 16:52:25 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	sort_top_top(t_stacks *st, t_info *pc0)
{
	if (st->a[st->pa] < st->b[st->pb + 1])
	{ // [4]  [5]
		action(st, "ra", 1);
		action(st, "pa", 1);
		action(st, "ra", 1);
	}
	else if (st->a[st->pa] > st->b[st->pb + 1])
	{ // [5]  [4]
		action(st, "pa", 1);
		action(st, "ra", 1);
		action(st, "ra", 1);
	}
	// if ((pc0-1)->lt == 'A')
	// {
	// 	printf("         A\n");
	// }
	// else if ((pc0-1)->lt == 'B')
	// {
	// 	printf("         B\n");
	// }


}


void	sort_3_elements(t_stacks *st, t_info *pc0, int *srt)
{
	// printf("NOW WE SORT 3 ELEMENTS\n");
	// printf("begin %d\n", srt[pc0->begin]);
	// printf("end  %d\n", srt[pc0->end - 1]);
	// printf("lt  %c\n", pc0->lt);

	if (pc0->lt == 'A' && pc0->amount + st->pa == st->n)
	{
		if (st->a[st->pa] < st->a[st->pa + 2] && st->a[st->pa + 2] < st->a[st->pa + 1])
		{ // 1 3 2, eg: "10 100 40"
			action(st, "rra", 1);
			action(st, "sa", 1);
		}
		else if (st->a[st->pa + 1] == srt[pc0->begin])
		{ // * 1 *
			if (st->a[st->pa] < st->a[st->pa + 2]) // 2 1 3
				action(st, "sa", 1);
			else if (st->a[st->pa] > st->a[st->pa + 2]) // 3 1 2
			{
				action(st, "ra", 1);
			}
		}
		else if (st->a[st->pa + 2] == srt[pc0->begin])
		{ // * * 1
			if (st->a[st->pa] < st->a[st->pa + 1]) // 2 3 1
				action(st, "rra", 1);
			else if (st->a[st->pa] > st->a[st->pa + 1]) // 3 2 1
			{
				action(st, "sa", 1);
				action(st, "rra", 1);
			}
		}
	}
	else if (pc0->lt == 'A')
	{
		if (st->a[st->pa] == srt[pc0->begin]) // 1 * *
		{ //works fine ; the lowest element is on top
			action(st, "ra", 1);
			sort_2_elements(st, pc0);
		}
		else if (st->a[st->pa + 1] == srt[pc0->begin]) // * 1 *
		{ //the lowest element is the second
			action(st, "sa", 1);
			action(st, "ra", 1);
			sort_2_elements(st, pc0);
		}
		else if (st->a[st->pa + 2] == srt[pc0->begin]) // * * 1
		{ 
			action(st, "pb", 1);
			action(st, "sa", 1);
			action(st, "ra", 1); // after that we have  two elements on both stacks
			sort_top_top(st, pc0);
		}
	}
	//след кусок никогда не будет. нет такого, чтобы в В осталось три элем, а А пустой
	// else if (pc0->lt == 'B' && pc0->amount + st->pb == st->n)
	// { //three elements alone
	// 	printf("OF COURSE\n");
	// 	if (st->b[st->pb + 1] == srt[pc0->begin]) //B: 1 * * далее пусто
	// 	{ //first elem in B is the lowest
	// 		action(st, "pa");
	// 		action(st, "pa");
	// 		action(st, "sa");
	// 		action(st, "pa");
	// 		if (st->a[st->pa] == srt[pc0->begin + 1]) //second lowest on the top of A: 2 1 3
	// 			action(st, "sa");
	// 		else if (st->a[st->pa] == srt[pc0->begin + 1]) //sec lowest is the third in A: 3 1 2
	// 			action(st, "ra");
	// 	}
	// 	else if (st->b[st->pb + 2] == srt[pc0->begin])
	// 	{ // B: * 1 *
	// 		action(st, "pa");
	// 		action(st, "pa");
	// 		action(st, "pa");
	// 		if (st->a[st->pa] == srt[pc0->begin + 1]) //A: 2 1 3
	// 			action(st, "sa");
	// 		else if (st->a[st->pa + 2] == srt[pc0->begin + 1]) //B: 3 1 2
	// 			action(st, "ra");
	// 	}
	// 	else if (st->b[st->pb + 3] == srt[pc0->begin])
	// 	{ // B: * * 1
	// 		action(st, "pa");
	// 		action(st, "pa");
	// 		if (st->a[st->pa] == srt[pc0->begin + 1]) // A: 2 3, B: 1
	// 			action(st, "pa");
	// 		else if (st->a[st->pa + 1] == srt[pc0->begin + 1]) // A: 3 2, B: 1
	// 		{
	// 			action(st, "sa");
	// 			action(st, "pa");
	// 		}
	// 	}
	// }
	else if (pc0->lt == 'B')
	{
		if (st->b[st->pb + 1] == srt[pc0->begin])
		{ // B: 1 * *
		// && st->b[st->pb + 2] == srt[pc0->begin + 1]
			action(st, "pa", 1);
			action(st, "ra", 1);
			action(st, "pa", 1); //push second element to A and work up from here
			sort_top_top(st, pc0);
			//замениил на функцию
			// if (st->a[st->pa] == srt[pc0->begin + 1]) //A: 2 [other elements] 1, B: 3
			// {
			// 	action(st, "ra");
			// 	action(st, "pa");
			// 	action(st, "ra");
			// }
			// else if (st->a[st->pa] == srt[pc0->begin + 2]) //A: 3 [] 1, B: 2
			// {
			// 	action(st, "pa");
			// 	action(st, "ra");
			// 	action(st, "ra");
			// }
		}
		else if (st->b[st->pb + 2] == srt[pc0->begin])
		{ // B: * 1 *

			action(st, "pa", 1);
			action(st, "pa", 1);
			action(st, "ra", 1);
			sort_top_top(st, pc0);
		}
		else if (st->b[st->pb + 3] == srt[pc0->begin])
		{ // B: * * 1
			action(st, "pa", 1);
			action(st, "pa", 1);
			action(st, "pa", 1);
			action(st, "ra", 1);
			// print_piece(*pc0);
			pc0->lt = 'A';
			pc0->begin++;
			pc0->amount--; 

		// printf("NNNU\n");
		// print_arrays(st);
			// print_piece(*pc0);

			sort_2_elements(st, pc0);
		// printf("NNNU\n");
		// print_arrays(st);

		}
			// printf("A Possibly here\n");
			// print_piece(pc0[0]);
			// printf("A Possibly here\n");
	}
	pc0->lt = 0;
	pc0->begin = 0;
	pc0->end = 0;
	pc0->amount = 0;
}

//gcc parse_args.c ft_atoi_backsp.c funs1.c ps.c sort2.c sort3.c sort4.c fun_print.c -o push_swap my_libft/libft.a
//gcc ps.c funs1.c sort4.c sort2.c sort3.c  && ./a.out
//python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

//./push_swap 182 342 313 484 195 169 31 227 214 300 277 332 377 430 466 228 95 224 200 237 81 249 479 387 211 323 471 74 13 381 356 205 475 19 353 303 122 58 162 424 167 149 222 455 383 209 135 433 92 470 443 395 223 20 66 394 358 307 239 183 141 488 90 371 87 142 493 284 250 78 357 273 457 270 460 109 212 188 389 359 497 374 321 30 462 75 84 327 456 151 399 64 196 439 329 491 429 41 492 306 246 391 311 292 52 4 144 350 100 179 299 104 485 38 192 367 8 382 191 158 79 199 345 244 201 213 459 155 123 204 157 469 436 147 206 33 341 15 96 426 9 378 216 319 405 354 236 316 474 390 489 379 410 403 305 434 37 114 366 375 252 173 496 478 365 7 55 189 336 344 361 477 269 420 337 42 328 415 145 99 259 138 40 128 111 351 83 93 427 263 417 80 468 308 18 180 473 53 266 255 283 175 174 499 218 134 69 231 210 288 440 117 472 447 198 290 260 253 304 279 71 125 51 121 98 45 408 86 362 208 309 423 29 465 272 463 280 278 289 11 448 271 97 60 257 23 500 108 494 243 414 91 137 442 166 44 372 146 346 203 396 139 126 454 26 325 160 115 274 388 6 348 385 437 431 370 294 386 88 322 355 219 1 285 409 487 106 349 168 490 363 445 154 428 397 245 401 338 406 291 165 57 177 261 226 320 25 364 419 110 105 347 254 152 72 312 22 268 421 330 136 435 113 256 39 343 232 241 132 446 17 34 24 411 12 85 392 194 318 47 171 221 369 352 286 82 425 498 293 197 10 215 32 133 438 89 185 482 314 28 452 148 217 404 49 103 16 186 230 398 335 170 62 120 102 21 384 302 265 451 54 248 112 181 326 229 287 46 331 240 76 600
